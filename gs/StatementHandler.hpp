// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_STATEMENTHANDLER_HPP
#define GS_STATEMENTHANDLER_HPP

#include <gs/IStatementHandler.hpp>
#include <gs/FunctionFactory.hpp>
#include <gs/IScript.hpp>
#include <gs/StatementFactory.hpp>
#include <gs/ExpressionFactory.hpp>
#include <boost/shared_ptr.hpp>

namespace gs
{

class StatementHandler : public IStatementHandler
{
public:
    StatementHandler(
        SharedIScript script, SharedFunctionFactory functionFactory, SharedStatementFactory statementFactory,
        SharedExpressionFactory expressionFactory)
        : script(script), functionFactory(functionFactory), statementFactory(statementFactory),
        expressionFactory(expressionFactory) { }
    virtual void end(unsigned int line);
    virtual void eof(unsigned int line);
    virtual void functionDef(unsigned int line, const std::string& name, const FunctionArgs& args);
    virtual void methodCall(
        unsigned int line, const std::string& object, const std::string& method, const FunctionArgs& args);
    virtual void returnStmt(unsigned line, const std::string& object);
    virtual void returnStmt(
        unsigned line, const std::string& object, const std::string& method, const FunctionArgs& args);
    virtual void variableDef(unsigned line, const std::string& name) { }
    virtual void variableDef(unsigned line, const std::string& name, const std::string& object) { }
    virtual void variableDef(
        unsigned int line, const std::string& name, const std::string& object,
        const std::string& method, const gs::FunctionArgs& args) { }
private:
    SharedIScript script;
    SharedFunctionFactory functionFactory;
    SharedStatementFactory statementFactory;
    SharedExpressionFactory expressionFactory;
    SharedIFunction function;
    FunctionArgs functionArgs;
    unsigned indexOfArg(const std::string& arg);
    ObjectIndices findObjectIndices(const gs::FunctionArgs& args);
};

typedef boost::shared_ptr<StatementHandler> SharedStatementHandler;

}
#endif /* GS_STATEMENTHANDLER_HPP */
