// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_PARSER_HPP
#define GS_PARSER_HPP

#include <gs/Script.hpp>
#include <boost/shared_ptr.hpp>
#include <gs/IParser.hpp>
#include <gs/IStatementHandler.hpp>

namespace gs
{

class Parser : public IParser
{
public:

    Parser(SharedIStatementHandler stmtHandler)
        : stmtHandler(stmtHandler) { }

    virtual void parse(const std::string& text);

private:
    SharedIStatementHandler stmtHandler;
    void parseLine(unsigned lineNo, const std::string& line);
};

typedef boost::shared_ptr<Parser> SharedParser;

}
#endif /* GS_PARSER_HPP */
