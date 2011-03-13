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
#include <gs/Parser.hpp>
#include <gs/StatementHandler.hpp>

namespace gs
{

class ScriptParser : public Parser
{
public:

    ScriptParser(SharedStatementHandler stmtHandler)
        : stmtHandler(stmtHandler) { }

    virtual void parse(const std::string& text);

private:
    SharedStatementHandler stmtHandler;
    void parseLine(unsigned lineNo, const std::string& line);
};

typedef boost::shared_ptr<ScriptParser> SharedScriptParser;

}
#endif /* GS_SCRIPTPARSER_HPP */
