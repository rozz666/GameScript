// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_SCRIPTCOMPILER_HPP
#define GS_SCRIPTCOMPILER_HPP

#include <boost/shared_ptr.hpp>
#include <gs/Compiler.hpp>
#include <gs/ScriptFactory.hpp>
#include <gs/ParserFactory.hpp>

namespace gs
{

class ScriptCompiler : public Compiler
{
public:
    ScriptCompiler(SharedScriptFactory scriptFactory, SharedParserFactory parserFactory)
        : scriptFactory(scriptFactory), parserFactory(parserFactory) { }
    virtual SharedScriptInterface compile(const std::string& source);
private:
    SharedScriptFactory scriptFactory;
    SharedParserFactory parserFactory;
};

typedef boost::shared_ptr<ScriptCompiler> SharedScriptCompiler;

}
#endif /* GS_SCRIPTCOMPILER_HPP */
