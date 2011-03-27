// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#include <gs/ScriptStatementHandler.hpp>
#include <gmock/gmock.h>
#include <gs/test/unit/ScriptInterfaceMock.hpp>
#include <gs/test/unit/FunctionFactoryMock.hpp>
#include <gs/test/unit/FunctionMock.hpp>
#include <gs/test/unit/StatementFactoryMock.hpp>
#include <gs/test/unit/StatementStub.hpp>
#include <gs/test/unit/ExpressionFactoryMock.hpp>
#include <gs/test/unit/ExpressionMock.hpp>
#include <boost/assign/list_of.hpp>

using namespace testing;
using boost::assign::list_of;

struct gs_ScriptStatementHandler : testing::Test
{
    gs::SharedFunctionMock function;
    gs::SharedFunctionFactoryMock functionFactory;
    gs::SharedStatementFactoryMock stmtFactory;
    gs::SharedScriptInterfaceMock script;
    gs::SharedExpressionFactoryMock exprFactory;
    gs::ScriptStatementHandler stmtHandler;
    gs::SharedStatement stmt;

    gs_ScriptStatementHandler()
        : function(new gs::FunctionMock), functionFactory(new gs::FunctionFactoryMock),
        stmtFactory(new gs::StatementFactoryMock), script(new gs::ScriptInterfaceMock),
        exprFactory(new gs::ExpressionFactoryMock),
        stmtHandler(script, functionFactory, stmtFactory, exprFactory), stmt(new gs::StatementStub) { }

    void setupFunction(const gs::FunctionArgs& args)
    {
        EXPECT_CALL(*functionFactory, createFunction(_))
            .WillOnce(Return(function));

        stmtHandler.functionDef(1, "asia", args);
    }
};

TEST_F(gs_ScriptStatementHandler, emptyFunction)
{
    std::string functionName = "asia";
    EXPECT_CALL(*functionFactory, createFunction(functionName))
        .WillOnce(Return(function));

    stmtHandler.functionDef(1, functionName, gs::FunctionArgs());

    EXPECT_CALL(*script, addFunction(gs::SharedFunction(function)));

    stmtHandler.end(2);
}

TEST_F(gs_ScriptStatementHandler, methodCallNoArgs)
{
    gs::FunctionArgs args = list_of("xx");
    setupFunction(args);

    std::string methodName = "y";
    EXPECT_CALL(*stmtFactory, createCallMethod(0, methodName, gs::ObjectIndices()))
        .WillOnce(Return(stmt));
    EXPECT_CALL(*function, addStatement(stmt));

    stmtHandler.methodCall(5, args[0], methodName, gs::FunctionArgs());
}

TEST_F(gs_ScriptStatementHandler, methodCallWithArgs)
{
    gs::FunctionArgs args = list_of("obj")("a")("b");
    setupFunction(args);

    std::string methodName = "y";
    gs::ObjectIndices indices = list_of(1)(2);
    EXPECT_CALL(*stmtFactory, createCallMethod(0, methodName, indices))
        .WillOnce(Return(stmt));
    EXPECT_CALL(*function, addStatement(stmt));

    gs::FunctionArgs callArgs = list_of(args[indices[0]])(args[indices[1]]);
    stmtHandler.methodCall(5, args[0], methodName, callArgs);
}

TEST_F(gs_ScriptStatementHandler, returnObject)
{
    gs::FunctionArgs args = list_of("abc")("def");
    setupFunction(args);
    unsigned objectIndex = 1;
    gs::SharedExpression expr(new gs::ExpressionMock);
    EXPECT_CALL(*exprFactory, createObject(objectIndex))
        .WillOnce(Return(expr));
    EXPECT_CALL(*stmtFactory, createReturn(expr))
        .WillOnce(Return(stmt));
    EXPECT_CALL(*function, addStatement(stmt));

    stmtHandler.returnStmt(7, args[objectIndex]);
}