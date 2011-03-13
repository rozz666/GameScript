// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_SCRIPTINTERFACEMOCK_HPP
#define GS_SCRIPTINTERFACEMOCK_HPP

#include <gs/ScriptInterface.hpp>
#include <gmock/gmock.h>

namespace gs
{

struct ScriptInterfaceMock : ScriptInterface
{
    MOCK_METHOD1(addFunction, void(SharedFunction));
    MOCK_METHOD2(callFunction, void(const std::string&, const gs::FunctionArgs&));
};

typedef boost::shared_ptr<ScriptInterfaceMock> SharedScriptInterfaceMock;

}
#endif /* GS_SCRIPTINTERFACEMOCK_HPP */
