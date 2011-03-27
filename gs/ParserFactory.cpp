// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#include <gs/ParserFactory.hpp>
#include <gs/ScriptParser.hpp>
#include <gs/ScriptStatementHandler.hpp>

namespace gs
{

SharedParser ParserFactory::createParser(SharedScriptInterface script)
{
    SharedFunctionFactory functionFactory(new FunctionFactory);
    SharedStatementFactory stmtFactory(new StatementFactory);
    SharedExpressionFactory exprFactory(new ExpressionFactory);
    SharedStatementHandler stmtHandler(new ScriptStatementHandler(script, functionFactory, stmtFactory, exprFactory));
    return SharedParser(new ScriptParser(stmtHandler));
}

}
