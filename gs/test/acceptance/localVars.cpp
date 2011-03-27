// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#include <gs/test/acceptance/ATFixture.hpp>
#include <gs/null.hpp>
#include <gs/test/unit/ObjectStub.hpp>
using namespace testing;

struct LocalVars : gs::ATFixture
{
};

TEST_F(LocalVars, argRefs)
{
    gs::SharedScriptInterface s = loadScript("localVar1.gs");
    args.push_back(gs::ObjectRef(new gs::ObjectStub));
    args.push_back(gs::ObjectRef(new gs::ObjectStub));
    EXPECT_CALL(static_cast<gs::MappedObjectMock&>(*obj), testMethod2(args[2], args[1]));
    s->callFunction("localVarTest1", args);
}

TEST_F(LocalVars, returnValueRef)
{
    gs::SharedScriptInterface s = loadScript("localVar2.gs");
    gs::ObjectRef ret(new gs::ObjectStub);
    EXPECT_CALL(static_cast<gs::MappedObjectMock&>(*obj), testMethod1())
        .WillOnce(Return(ret));
    ASSERT_TRUE(s->callFunction("localVarTest2", args) == ret);
}

TEST_F(LocalVars, varRef)
{
    gs::SharedScriptInterface s = loadScript("localVar3.gs");
    gs::ObjectRef ret(new gs::ObjectStub);
    EXPECT_CALL(static_cast<gs::MappedObjectMock&>(*obj), testMethod1())
        .WillOnce(Return(ret));
    ASSERT_TRUE(s->callFunction("localVarTest3", args) == ret);
}

TEST_F(LocalVars, defaultVars)
{
    gs::SharedScriptInterface s = loadScript("localVar4.gs");
    EXPECT_CALL(static_cast<gs::MappedObjectMock&>(*obj), testMethod2(gs::null, gs::null));
    s->callFunction("localVarTest4", args);
}

TEST_F(LocalVars, varAssignment)
{
    gs::SharedScriptInterface s = loadScript("localVar5.gs");
    args.push_back(gs::ObjectRef(new gs::ObjectStub));
    EXPECT_CALL(static_cast<gs::MappedObjectMock&>(*obj), testMethod2(args[1], args[1]));
    s->callFunction("localVarTest5", args);
}

TEST_F(LocalVars, argAssignment)
{
    gs::SharedScriptInterface s = loadScript("localVar6.gs");
    args.push_back(gs::ObjectRef(new gs::ObjectStub));
    args.push_back(gs::ObjectRef(new gs::ObjectStub));
    EXPECT_CALL(static_cast<gs::MappedObjectMock&>(*obj), testMethod2(args[2], args[1]));
    s->callFunction("localVarTest6", args);
}
