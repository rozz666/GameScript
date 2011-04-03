// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#include <gs/ScriptStatementHandler.hpp>
#include <boost/bind.hpp>

namespace gs
{

void ScriptStatementHandler::end(unsigned int line)
{
    script->addFunction(function);
}

void ScriptStatementHandler::eof(unsigned int line)
{
}

void ScriptStatementHandler::functionDef(unsigned int line, const std::string& name, const gs::FunctionArgs& args)
{
    function = functionFactory->createFunction(name);
    functionArgs = args;
}

void ScriptStatementHandler::methodCall(
    unsigned int line, const std::string& object, const std::string& method, const gs::FunctionArgs& args)
{
    ObjectIndices indices = findObjectIndices(args);
    function->addStatement(statementFactory->createCallMethod(0, method, indices));
}

unsigned ScriptStatementHandler::indexOfArg(const std::string& arg)
{
    return std::distance(functionArgs.begin(), std::find(functionArgs.begin(), functionArgs.end(), arg));
}

ObjectIndices ScriptStatementHandler::findObjectIndices(const gs::FunctionArgs& args)
{
    ObjectIndices indices(args.size());
    std::transform(
        args.begin(), args.end(), indices.begin(), boost::bind(&ScriptStatementHandler::indexOfArg, this, _1));
    return indices;
}

void ScriptStatementHandler::returnStmt(unsigned line, const std::string& object)
{
    function->addStatement(statementFactory->createReturn(expressionFactory->createObject(indexOfArg(object))));
}

void ScriptStatementHandler::returnStmt(
    unsigned line, const std::string& object, const std::string& method, const FunctionArgs& args)
{
    ObjectIndices indices = findObjectIndices(args);
    SharedIExpression expr = expressionFactory->createMethodCall(indexOfArg(object), method, indices);
    function->addStatement(statementFactory->createReturn(expr));
}

}
