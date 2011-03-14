// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#include <gs/ScriptCompiler.hpp>
#include <gmock/gmock.h>
#include <gs/test/unit/ScriptFactoryMock.hpp>
#include <gs/test/unit/ScriptInterfaceMock.hpp>
#include <gs/test/unit/StatementHandlerMock.hpp>
#include <gs/test/unit/ParserFactoryMock.hpp>
#include <gs/test/unit/ParserMock.hpp>

using namespace testing;

struct gs_ScriptCompiler : testing::Test
{
};

TEST_F(gs_ScriptCompiler, compile)
{
    gs::SharedScriptInterfaceMock script(new gs::ScriptInterfaceMock);
    gs::SharedScriptFactoryMock scriptFactory(new gs::ScriptFactoryMock);
    gs::SharedParserMock parser(new gs::ParserMock);
    gs::SharedParserFactoryMock parserFactory(new gs::ParserFactoryMock);
    gs::ScriptCompiler compiler(scriptFactory, parserFactory);

    std::string source = "abc";

    EXPECT_CALL(*scriptFactory, createScript())
        .WillOnce(Return(script));
    EXPECT_CALL(*parserFactory, createParser(gs::SharedScriptInterface(script)))
        .WillOnce(Return(parser));
    EXPECT_CALL(*parser, parse(source));

    ASSERT_TRUE(compiler.compile(source) == script);
}
