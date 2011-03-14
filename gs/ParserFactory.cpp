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
#include "ScriptStatementHandler.hpp"

namespace gs
{

SharedParser ParserFactory::createParser(SharedScriptInterface script)
{
    SharedFunctionFactory functionFactory(new FunctionFactory);
    SharedStatementFactory stmtFactory(new StatementFactory);
    SharedStatementHandler stmtHandler(new ScriptStatementHandler(script, functionFactory, stmtFactory));
    return SharedParser(new ScriptParser(stmtHandler));
}

}
