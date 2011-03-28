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
#include <boost/assign/list_of.hpp>

using namespace testing;
using boost::assign::list_of;

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
        args = list_of("xyz5")("y");
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
    source = " abc.xyz() \no.m(x, y) ";
    {
        InSequence seq;
        gs::FunctionArgs args;
        EXPECT_CALL(*statementHandler, methodCall(1, "abc", "xyz", args));
        args = list_of("x")("y");
        EXPECT_CALL(*statementHandler, methodCall(2, "o", "m", args));
        EXPECT_CALL(*statementHandler, eof(_));
    }
    parse();
}

TEST_F(gs_ScriptParser, returnStatement)
{
    source = " return x \nreturn zzz ";
    {
        InSequence seq;
        gs::FunctionArgs args;
        EXPECT_CALL(*statementHandler, returnStmt(1, "x"));
        EXPECT_CALL(*statementHandler, returnStmt(2, "zzz"));
        EXPECT_CALL(*statementHandler, eof(_));
    }
    parse();
}

TEST_F(gs_ScriptParser, returnStatementMethodCall)
{
    source = " return x.m() \nreturn zzz.dd(uu, bb) ";
    {
        InSequence seq;
        gs::FunctionArgs args;
        EXPECT_CALL(*statementHandler, returnStmt(1, "x", "m", args));
        args = list_of("uu")("bb");
        EXPECT_CALL(*statementHandler, returnStmt(2, "zzz", "dd", args));
        EXPECT_CALL(*statementHandler, eof(_));
    }
    parse();
}

TEST_F(gs_ScriptParser, defVar)
{
    source = " var abc \n var cde ";
    {
        InSequence seq;
        EXPECT_CALL(*statementHandler, variableDef(1, "abc"));
        EXPECT_CALL(*statementHandler, variableDef(2, "cde"));
        EXPECT_CALL(*statementHandler, eof(_));
    }
    parse();
}

TEST_F(gs_ScriptParser, defVarWithExpr)
{
    source = " var x = y \n var z = o.m(a, b) ";
    {
        InSequence seq;
        EXPECT_CALL(*statementHandler, variableDef(1, "x", "y"));
        gs::FunctionArgs args = list_of("a")("b");
        EXPECT_CALL(*statementHandler, variableDef(2, "z", "o", "m", args));
        EXPECT_CALL(*statementHandler, eof(_));
    }
    parse();
}
