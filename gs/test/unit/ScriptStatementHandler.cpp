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
#include <boost/assign/list_of.hpp>

using namespace testing;

struct gs_ScriptStatementHandler : testing::Test
{
    gs::SharedFunctionMock function;
    gs::SharedFunctionFactoryMock functionFactory;
    gs::SharedStatementFactoryMock stmtFactory;
    gs::SharedScriptInterfaceMock script;
    gs::ScriptStatementHandler stmtHandler;

    gs_ScriptStatementHandler()
        : function(new gs::FunctionMock), functionFactory(new gs::FunctionFactoryMock),
        stmtFactory(new gs::StatementFactoryMock), script(new gs::ScriptInterfaceMock),
        stmtHandler(script, functionFactory, stmtFactory) { }
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
    gs::SharedStatement stmt(new gs::StatementStub);
    EXPECT_CALL(*functionFactory, createFunction(_))
        .WillOnce(Return(function));
    gs::FunctionArgs args = boost::assign::list_of("xx");

    stmtHandler.functionDef(1, "asia", args);

    std::string methodName = "y";
    EXPECT_CALL(*stmtFactory, createCallMethod(0, methodName, gs::ObjectIndices()))
        .WillOnce(Return(stmt));
    EXPECT_CALL(*function, addStatement(stmt));

    stmtHandler.methodCall(5, args[0], methodName, gs::FunctionArgs());
}