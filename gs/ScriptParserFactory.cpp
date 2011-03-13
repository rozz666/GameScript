// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#include <gs/ScriptParserFactory.hpp>

namespace gs
{

SharedScriptParser ScriptParserFactory::createScriptParser()
{
    SharedScriptFactory scriptFactory(new ScriptFactory);
    SharedFunctionFactory functionFactory(new FunctionFactory);
    SharedScriptParser parser(new ScriptParser(scriptFactory, functionFactory));
    return parser;
}

}
