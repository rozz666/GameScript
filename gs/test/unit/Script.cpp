// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#include <gs/Script.hpp>
#include <gs/test/unit/FunctionMock.hpp>
#include <gmock/gmock.h>
#include <gs/test/unit/ObjectStub.hpp>

using namespace testing;

struct gs_Script : testing::Test
{
};

TEST_F(gs_Script, addAndCallTwoFunctions)
{
    gs::Script script;
    gs::SharedFunctionMock f1(new gs::FunctionMock);
    gs::SharedFunctionMock f2(new gs::FunctionMock);
    gs::CallArgs args;
    std::string name1 = "abc";
    std::string name2 = "xyz";
    gs::ObjectRef obj1(new gs::ObjectStub);
    gs::ObjectRef obj2(new gs::ObjectStub);
    EXPECT_CALL(*f1, getName())
        .WillRepeatedly(Return(name1));
    script.addFunction(f1);
    EXPECT_CALL(*f2, getName())
        .WillRepeatedly(Return(name2));
    script.addFunction(f2);

    EXPECT_CALL(*f1, run(Ref(args)))
        .WillOnce(Return(obj1));
    ASSERT_TRUE(script.callFunction(name1, args) == obj1);
    EXPECT_CALL(*f2, run(Ref(args)))
        .WillOnce(Return(obj2));
    ASSERT_TRUE(script.callFunction(name2, args) == obj2);
}
