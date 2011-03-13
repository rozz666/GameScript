// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#include <gs/ScriptParser.hpp>
#include <boost/regex.hpp>
#include <sstream>

namespace gs
{

SharedScriptInterface ScriptParser::parse(const std::string& text)
{
    SharedScriptInterface script = scriptFactory->createScript();
    parseLines(text, script);
    return script;
}

void ScriptParser::parseLine(const std::string& line, SharedScriptInterface script)
{
    boost::regex def("def +(.+)\\(\\)");
    boost::match_results<std::string::const_iterator> res;
    if (boost::regex_match(line, res, def))
    {
        script->addFunction(functionFactory->createFunction(res[1].str()));
    }
}

void ScriptParser::parseLines(const std::string& text, SharedScriptInterface script)
{
    std::istringstream ss(text);
    std::string line;
    while (std::getline(ss, line))
    {
        parseLine(line, script);
    }
}

}
