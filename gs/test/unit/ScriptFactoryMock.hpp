// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_SCRIPTFACTORYMOCK_HPP
#define GS_SCRIPTFACTORYMOCK_HPP

#include <gs/ScriptFactory.hpp>
#include <gmock/gmock.h>

namespace gs
{

struct ScriptFactoryMock : ScriptFactory
{
    MOCK_METHOD0(createScript, SharedScriptInterface());
};

typedef boost::shared_ptr<ScriptFactoryMock> SharedScriptFactoryMock;

}
#endif /* GS_SCRIPTFACTORYMOCK_HPP */
