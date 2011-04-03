// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_PARSERFACTORYMOCK_HPP
#define GS_PARSERFACTORYMOCK_HPP

#include <gs/ParserFactory.hpp>
#include <gmock/gmock.h>

namespace gs
{

struct ParserFactoryMock : ParserFactory
{
    MOCK_METHOD1(createParser, SharedIParser(SharedIScript script));
};

typedef boost::shared_ptr<ParserFactoryMock> SharedParserFactoryMock;

}
#endif /* GS_PARSERFACTORYMOCK_HPP */
