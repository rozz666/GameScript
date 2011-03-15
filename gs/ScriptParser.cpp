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
    std::vector<std::string> args;
};

template <typename RuleType>
struct Rule
{
    typedef boost::spirit::qi::rule<std::string::const_iterator, RuleType(), boost::spirit::ascii::space_type> Type;
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
    (std::vector<std::string>, args)
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

    Rule<std::string>::Type identifier = qi::lexeme[qi::char_("a-zA-Z_") >> *qi::char_("a-zA-Z0-9_")];
    Rule<FunctionDef>::Type functionDefRule = "def" >> identifier >> "(" >> -(identifier % ",") >> ")" >> qi::eoi;
    Rule<void>::Type endRule = "end" >> qi::eoi;
    Rule<MethodCall>::Type methodCallRule =
        identifier >> "." >> identifier >> "(" >> -(identifier % ",") >> ")" >> qi::eoi;
    Rule<std::string>::Type returnStmt = "return" >> identifier >> qi::eoi;

    FunctionDef functionDef;
    MethodCall methodCall;
    std::string objectName;

    if (qi::phrase_parse(line.begin(), line.end(), functionDefRule, ascii::space, functionDef))
    {
        stmtHandler->functionDef(lineNo, functionDef.name, functionDef.args);
    }
    else if (qi::phrase_parse(line.begin(), line.end(), endRule, ascii::space))
    {
        stmtHandler->end(lineNo);
    }
    else if (qi::phrase_parse(line.begin(), line.end(), methodCallRule, ascii::space, methodCall))
    {
        stmtHandler->methodCall(lineNo, methodCall.object, methodCall.method, methodCall.args);
    }
    else if (qi::phrase_parse(line.begin(), line.end(), returnStmt, ascii::space, objectName))
    {
        stmtHandler->returnStmt(lineNo, objectName);
    }
}

}
