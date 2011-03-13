// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_SCRIPTPARSERFACTORYMOCK_HPP
#define GS_SCRIPTPARSERFACTORYMOCK_HPP

#include <gs/ScriptParserFactory.hpp>
#include <gmock/gmock.h>

namespace gs
{

struct ScriptParserFactoryMock : ScriptParserFactory
{
};

typedef boost::shared_ptr<ScriptParserFactoryMock> SharedScriptParserFactoryMock;

}
#endif /* GS_SCRIPTPARSERFACTORYMOCK_HPP */
