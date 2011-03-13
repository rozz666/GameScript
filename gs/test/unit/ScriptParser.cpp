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
#include <gs/test/unit/StatementHandlerMock.hpp>

using namespace testing;

struct gs_ScriptParser : testing::Test
{
    std::string source;
    gs::SharedStatementHandlerMock statementHandler;
    gs::ScriptParser parser;

    gs_ScriptParser()
        : statementHandler(new gs::StatementHandlerMock), parser(statementHandler) { }

    void parse()
    {
        parser.parse(source);
    }
};

TEST_F(gs_ScriptParser, functionDefs)
{
    source = " def functionName1 ( )\n\ndef   functionName2(xyz5, y )\n";
    {
        InSequence seq;
        gs::FunctionArgs args;
        EXPECT_CALL(*statementHandler, functionDef(1, "functionName1", args));
        args.push_back("xyz5");
        args.push_back("y");
        EXPECT_CALL(*statementHandler, functionDef(3, "functionName2", args));
        EXPECT_CALL(*statementHandler, eof(4));
    }
    parse();
}

TEST_F(gs_ScriptParser, ends)
{
    source = " end \nend";
    {
        InSequence seq;
        EXPECT_CALL(*statementHandler, end(1));
        EXPECT_CALL(*statementHandler, end(2));
        EXPECT_CALL(*statementHandler, eof(3));
    }
    parse();
}

TEST_F(gs_ScriptParser, methodCall)
{
    source = " abc.xyz() ";
    {
        InSequence seq;
        EXPECT_CALL(*statementHandler, methodCall(1, "abc", "xyz"));
        EXPECT_CALL(*statementHandler, eof(_));
    }
    parse();
}
