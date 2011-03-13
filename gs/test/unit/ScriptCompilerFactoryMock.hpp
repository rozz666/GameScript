// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_SCRIPTCOMPILERFACTORYMOCK_HPP
#define GS_SCRIPTCOMPILERFACTORYMOCK_HPP

#include <gs/ScriptCompilerFactory.hpp>
#include <gmock/gmock.h>

namespace gs
{

struct ScriptCompilerFactoryMock : ScriptCompilerFactory
{
};

typedef boost::shared_ptr<ScriptCompilerFactoryMock> SharedScriptCompilerFactoryMock;

}
#endif /* GS_SCRIPTCOMPILERFACTORYMOCK_HPP */
