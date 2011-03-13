// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_SCRIPTPARSER_HPP
#define GS_SCRIPTPARSER_HPP

#include <gs/Script.hpp>
#include <boost/shared_ptr.hpp>
#include <gs/ScriptFactory.hpp>
#include <gs/FunctionFactory.hpp>

namespace gs
{

class ScriptParser
{
public:

    ScriptParser(SharedScriptFactory scriptFactory, SharedFunctionFactory functionFactory)
        : scriptFactory(scriptFactory), functionFactory(functionFactory) { }

    SharedScriptInterface parse(const std::string& text);

private:
    SharedScriptFactory scriptFactory;
    SharedFunctionFactory functionFactory;
    void parseLine(const std::string& line, SharedScriptInterface script);
    void parseLines(const std::string& text, SharedScriptInterface script);
};

typedef boost::shared_ptr<ScriptParser> SharedScriptParser;

}
#endif /* GS_SCRIPTPARSER_HPP */
