// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#include <gs/ParserFactory.hpp>
#include <gs/Parser.hpp>
#include <gs/ScriptStatementHandler.hpp>

namespace gs
{

SharedIParser ParserFactory::createParser(SharedIScript script)
{
    SharedFunctionFactory functionFactory(new FunctionFactory);
    SharedStatementFactory stmtFactory(new StatementFactory);
    SharedExpressionFactory exprFactory(new ExpressionFactory);
    SharedIStatementHandler stmtHandler(new ScriptStatementHandler(script, functionFactory, stmtFactory, exprFactory));
    return SharedIParser(new Parser(stmtHandler));
}

}
