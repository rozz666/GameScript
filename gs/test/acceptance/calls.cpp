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

struct Calls : gs::ATFixture
{
};

TEST_F(Calls, callNoArgs)
{
    gs::SharedIScript s = loadScript("callTest1.gs");
    EXPECT_CALL(static_cast<gs::MappedObjectMock&>(*obj), testMethod1());
    s->callFunction("test1", args);
}

TEST_F(Calls, callTwoArgs)
{
    gs::SharedIScript s = loadScript("callTest2.gs");
    args.push_back(gs::ObjectRef(new gs::ObjectStub));
    args.push_back(gs::ObjectRef(new gs::ObjectStub));
    EXPECT_CALL(static_cast<gs::MappedObjectMock&>(*obj), testMethod2(args[1], args[2]));
    s->callFunction("test2", args);
}