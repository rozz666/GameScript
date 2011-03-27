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

#include <boost/shared_ptr.hpp>
#include <vector>
#include <string>

namespace gs
{

typedef std::vector<std::string> FunctionArgs;

class StatementHandler
{
public:
    virtual ~StatementHandler() { }
    virtual void functionDef(unsigned line, const std::string& name, const FunctionArgs& args) = 0;
    virtual void end(unsigned line) = 0;
    virtual void eof(unsigned line) = 0;
    virtual void methodCall(
        unsigned int line, const std::string& object, const std::string& method, const FunctionArgs& args) = 0;
    virtual void returnStmt(unsigned line, const std::string& object) = 0;
    virtual void returnStmt(
        unsigned line, const std::string& object, const std::string& method, const FunctionArgs& args) = 0;
protected:
    StatementHandler() { }
    StatementHandler(const StatementHandler& ) { }
    StatementHandler& operator=(const StatementHandler& ) { return *this; }
};

typedef boost::shared_ptr<StatementHandler> SharedStatementHandler;

}
#endif /* GS_STATEMENTHANDLER_HPP */
