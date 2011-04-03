// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#include <gs/Compiler.hpp>
#include <gs/test/unit/ScriptFactoryMock.hpp>
#include <gs/test/unit/ScriptMock.hpp>
#include <gs/test/unit/StatementHandlerMock.hpp>
#include <gs/test/unit/ParserFactoryMock.hpp>
#include <gs/test/unit/ParserMock.hpp>
#include <gmock/gmock.h>

using namespace testing;

struct gs_ScriptCompiler : testing::Test
{
};

TEST_F(gs_ScriptCompiler, compile)
{
    gs::SharedScriptMock script(new gs::ScriptMock);
    gs::SharedScriptFactoryMock scriptFactory(new gs::ScriptFactoryMock);
    gs::SharedParserMock parser(new gs::ParserMock);
    gs::SharedParserFactoryMock parserFactory(new gs::ParserFactoryMock);
    gs::Compiler compiler(scriptFactory, parserFactory);

    std::string source = "abc";

    EXPECT_CALL(*scriptFactory, createScript())
        .WillOnce(Return(script));
    EXPECT_CALL(*parserFactory, createParser(gs::SharedIScript(script)))
        .WillOnce(Return(parser));
    EXPECT_CALL(*parser, parse(source));

    ASSERT_TRUE(compiler.compile(source) == script);
}
