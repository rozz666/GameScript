// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#include <gs/ScriptParser.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/fusion/adapted/struct/adapt_struct.hpp>
#include <sstream>


namespace gs
{

struct FunctionDef
{
    std::string name;
    std::vector<std::string> args;
};

struct MethodCall
{
    std::string object;
    std::string method;
};

}

BOOST_FUSION_ADAPT_STRUCT(
    gs::FunctionDef,
    (std::string, name)
    (std::vector<std::string>, args)
)

BOOST_FUSION_ADAPT_STRUCT(
    gs::MethodCall,
    (std::string, object)
    (std::string, method)
)

namespace gs
{

void ScriptParser::parse(const std::string& text)
{
    std::istringstream ss(text);
    std::string line;
    unsigned lineNo = 1;
    while (std::getline(ss, line))
    {
        parseLine(lineNo, line);
        ++lineNo;
    }
    stmtHandler->eof(lineNo);
}

void ScriptParser::parseLine(unsigned lineNo, const std::string& line)
{
    namespace qi = boost::spirit::qi;
    namespace ascii = boost::spirit::ascii;

    qi::rule<std::string::const_iterator, std::string(), ascii::space_type> identifier =
        qi::lexeme[qi::char_("a-zA-Z_") >> *qi::char_("a-zA-Z0-9_")];

    FunctionDef functionDef;
    MethodCall methodCall;

    if (qi::phrase_parse(
        line.begin(), line.end(),
        "def" >> identifier >> "(" >> -(identifier % ",") >> ")" >> qi::eoi,
        ascii::space, functionDef))
    {
        stmtHandler->functionDef(lineNo, functionDef.name, functionDef.args);
    }
    else if (qi::phrase_parse(line.begin(), line.end(), "end" >> qi::eoi, ascii::space))
    {
        stmtHandler->end(lineNo);
    }
    else if (qi::phrase_parse(
        line.begin(), line.end(),
        identifier >> "." >> identifier >> "()" >> qi::eoi,
        ascii::space, methodCall))
    {
        stmtHandler->methodCall(lineNo, methodCall.object, methodCall.method);
    }
}

}
