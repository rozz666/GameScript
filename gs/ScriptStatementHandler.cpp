// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#include <gs/ScriptStatementHandler.hpp>

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
}

void ScriptStatementHandler::methodCall(
    unsigned int line, const std::string& object, const std::string& method, const gs::FunctionArgs& args)
{
    function->addStatement(statementFactory->createCallMethod(0, method, ObjectIndices()));
}

}
