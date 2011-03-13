// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#include <gs/ScriptParser.hpp>
#include <gmock/gmock.h>
#include <gs/test/unit/FunctionMock.hpp>
#include <gs/test/unit/ScriptFactoryMock.hpp>
#include <gs/test/unit/FunctionFactoryMock.hpp>
#include <gs/test/unit/ScriptInterfaceMock.hpp>

using namespace testing;

struct gs_ScriptParser : testing::Test
{
};

TEST_F(gs_ScriptParser, emptyFunction)
{
    gs::SharedFunctionMock f1(new gs::FunctionMock);
    gs::SharedFunctionMock f2(new gs::FunctionMock);
    gs::SharedScriptInterfaceMock script(new gs::ScriptInterfaceMock);
    // returned mocks have to be declared BEFORE factory mocks due to Google Mock bug
    gs::SharedFunctionFactoryMock functionFactory(new gs::FunctionFactoryMock);
    gs::SharedScriptFactoryMock scriptFactory(new gs::ScriptFactoryMock);
    gs::ScriptParser parser(scriptFactory, functionFactory);

    std::string source = "def functionName1()\nend\ndef   functionName2()\nend";

    EXPECT_CALL(*scriptFactory, createScript())
        .WillOnce(Return(script));
    EXPECT_CALL(*functionFactory, createFunction("functionName1"))
        .WillOnce(Return(f1));
    EXPECT_CALL(*functionFactory, createFunction("functionName2"))
        .WillOnce(Return(f2));
    EXPECT_CALL(*script, addFunction(gs::SharedFunction(f1)));
    EXPECT_CALL(*script, addFunction(gs::SharedFunction(f2)));

    ASSERT_TRUE(parser.parse(source) == script);
}
