// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_SCRIPTSTATEMENTHANDLER_HPP
#define GS_SCRIPTSTATEMENTHANDLER_HPP

#include <boost/shared_ptr.hpp>
#include <gs/StatementHandler.hpp>
#include <gs/FunctionFactory.hpp>
#include <gs/ScriptInterface.hpp>
#include <gs/StatementFactory.hpp>

namespace gs
{

class ScriptStatementHandler : public StatementHandler
{
public:
    ScriptStatementHandler(
        SharedScriptInterface script, SharedFunctionFactory functionFactory, SharedStatementFactory statementFactory)
        : script(script), functionFactory(functionFactory), statementFactory(statementFactory) { }
    virtual void end(unsigned int line);
    virtual void eof(unsigned int line);
    virtual void functionDef(unsigned int line, const std::string& name, const FunctionArgs& args);
    virtual void methodCall(
        unsigned int line, const std::string& object, const std::string& method, const FunctionArgs& args);
private:
    SharedScriptInterface script;
    SharedFunctionFactory functionFactory;
    SharedStatementFactory statementFactory;
    SharedFunction function;
    FunctionArgs functionArgs;
    unsigned indexOfArg(const std::string& arg);
    ObjectIndices findObjectIndices(const gs::FunctionArgs& args);
};

typedef boost::shared_ptr<ScriptStatementHandler> SharedScriptStatementHandler;

}
#endif /* GS_SCRIPTSTATEMENTHANDLER_HPP */