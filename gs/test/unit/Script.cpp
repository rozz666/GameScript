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

using namespace testing;

struct gs_Script : testing::Test
{
};

TEST_F(gs_Script, addAndCallOneFunction)
{
    gs::Script script;
    gs::SharedFunctionMock f(new gs::FunctionMock);
    gs::FunctionArgs args;
    std::string name = "abc";
    EXPECT_CALL(*f, getName())
        .WillRepeatedly(Return(name));
    script.addFunction(f);

    EXPECT_CALL(*f, run(Ref(args)))
        .Times(1);
    script.callFunction(name, args);
}
