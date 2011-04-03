// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#include <gs/ScriptCompilerFactory.hpp>
#include <gs/Compiler.hpp>

namespace gs
{

SharedICompiler ScriptCompilerFactory::createCompiler()
{
    SharedScriptFactory scriptFactory(new ScriptFactory);
    SharedParserFactory parserFactory(new ParserFactory);
    return SharedICompiler(new Compiler(scriptFactory, parserFactory));
}

}
