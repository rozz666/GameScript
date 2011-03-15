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

struct Returns : gs::ATFixture
{
};

TEST_F(Returns, returnArg)
{
    gs::SharedScriptInterface s = loadScript("returnTest1.gs");
    ASSERT_TRUE(s->callFunction("returnTest", args) == obj);
}

TEST_F(Returns, returnMethodCallNoArgs)
{
    gs::SharedScriptInterface s = loadScript("returnTest2.gs");
    gs::ObjectRef obj2(new gs::ObjectStub);
    EXPECT_CALL(static_cast<gs::MappedObjectMock&>(*obj), testMethod1())
        .WillOnce(Return(obj2));
    ASSERT_TRUE(s->callFunction("returnTest", args) == obj2);
}

TEST_F(Returns, returnMethodCallTwoArgs)
{
    gs::SharedScriptInterface s = loadScript("returnTest3.gs");
    gs::ObjectRef obj2(new gs::ObjectStub);
    args.push_back(gs::ObjectRef(new gs::ObjectStub));
    args.push_back(gs::ObjectRef(new gs::ObjectStub));
    EXPECT_CALL(static_cast<gs::MappedObjectMock&>(*obj), testMethod2(args[1], args[2]))
        .WillOnce(Return(obj2));
    ASSERT_TRUE(s->callFunction("returnTest", args) == obj2);
}
