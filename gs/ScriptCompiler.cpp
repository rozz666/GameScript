// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#include <gs/ScriptCompiler.hpp>
#include <gs/Script.hpp>

namespace gs
{

SharedScriptInterface ScriptCompiler::compile(const std::string& source)
{
    SharedScriptInterface script = scriptFactory->createScript();
    SharedParser parser = parserFactory->createParser(script);
    parser->parse(source);
    return script;
}

}
