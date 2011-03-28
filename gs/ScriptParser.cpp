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
#include <boost/variant.hpp>
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
    std::string method;
    std::vector<std::string> args;
};

struct ObjectMethodCall
{
    std::string object;
    MethodCall methodCall;
};

struct ObjectExpression
{
    std::string object;
    boost::optional<MethodCall> methodCall;
};

struct VariableDefinition
{
    std::string name;
    boost::optional<ObjectExpression> value;
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
    (std::string, method)
    (std::vector<std::string>, args)
)

BOOST_FUSION_ADAPT_STRUCT(
    gs::ObjectMethodCall,
    (std::string, object)
    (gs::MethodCall, methodCall)
)

BOOST_FUSION_ADAPT_STRUCT(
    gs::ObjectExpression,
    (std::string, object)
    (boost::optional<gs::MethodCall>, methodCall)
)

BOOST_FUSION_ADAPT_STRUCT(
    gs::VariableDefinition,
    (std::string, name)
    (boost::optional<gs::ObjectExpression>, value)
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
    Rule<MethodCall>::Type methodCall = "." >> identifier >> "(" >> -(identifier % ",") >> ")";
    Rule<ObjectMethodCall>::Type objectMethodCallRule = identifier >> methodCall >> qi::eoi;
    Rule<ObjectExpression>::Type objectExpression = identifier >> -methodCall;
    Rule<ObjectExpression>::Type returnStmtRule = "return" >> objectExpression >> qi::eoi;
    Rule<VariableDefinition>::Type varDefRule = "var" >> identifier >> -('=' >> objectExpression) >> qi::eoi;

    FunctionDef functionDef;
    ObjectMethodCall objectMethodCall;
    ObjectExpression ret;
    VariableDefinition varDef;

    if (qi::phrase_parse(line.begin(), line.end(), functionDefRule, ascii::space, functionDef))
    {
        stmtHandler->functionDef(lineNo, functionDef.name, functionDef.args);
    }
    else if (qi::phrase_parse(line.begin(), line.end(), endRule, ascii::space))
    {
        stmtHandler->end(lineNo);
    }
    else if (qi::phrase_parse(line.begin(), line.end(), objectMethodCallRule, ascii::space, objectMethodCall))
    {
        stmtHandler->methodCall(
            lineNo, objectMethodCall.object, objectMethodCall.methodCall.method, objectMethodCall.methodCall.args);
    }
    else if (qi::phrase_parse(line.begin(), line.end(), returnStmtRule, ascii::space, ret))
    {
        if (ret.methodCall)
        {
            stmtHandler->returnStmt(lineNo, ret.object, ret.methodCall->method, ret.methodCall->args);
        }
        else
        {
            stmtHandler->returnStmt(lineNo, ret.object);
        }
    }
    else if (qi::phrase_parse(line.begin(), line.end(), varDefRule, ascii::space, varDef))
    {
        if (varDef.value)
        {
            if (varDef.value->methodCall)
            {
                stmtHandler->variableDef(lineNo, varDef.name, varDef.value->object, varDef.value->methodCall->method, varDef.value->methodCall->args);
            }
            else
            {
                stmtHandler->variableDef(lineNo, varDef.name, varDef.value->object);
            }
        }
        else
        {
            stmtHandler->variableDef(lineNo, varDef.name);
        }
    }
}

}
