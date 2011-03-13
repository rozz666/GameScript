// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_PARSERMOCK_HPP
#define GS_PARSERMOCK_HPP

#include <gs/Parser.hpp>
#include <gmock/gmock.h>

namespace gs
{

struct ParserMock : Parser
{
    MOCK_METHOD1(parse, void(const std::string& text));
};

typedef boost::shared_ptr<ParserMock> SharedParserMock;

}
#endif /* GS_PARSERMOCK_HPP */
