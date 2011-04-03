// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_ISTATEMENTHANDLER_HPP
#define GS_ISTATEMENTHANDLER_HPP

#include <boost/shared_ptr.hpp>
#include <vector>
#include <string>

namespace gs
{

typedef std::vector<std::string> FunctionArgs;

class IStatementHandler
{
public:
    virtual ~IStatementHandler() { }
    virtual void functionDef(unsigned line, const std::string& name, const FunctionArgs& args) = 0;
    virtual void end(unsigned line) = 0;
    virtual void eof(unsigned line) = 0;
    virtual void methodCall(
        unsigned int line, const std::string& object, const std::string& method, const FunctionArgs& args) = 0;
    virtual void returnStmt(unsigned line, const std::string& object) = 0;
    virtual void returnStmt(
        unsigned line, const std::string& object, const std::string& method, const FunctionArgs& args) = 0;
    virtual void variableDef(unsigned line, const std::string& name) = 0;
    virtual void variableDef(unsigned line, const std::string& name, const std::string& object) = 0;
    virtual void variableDef(
        unsigned line, const std::string& name, const std::string& object,
        const std::string& method, const FunctionArgs& args) = 0;
protected:
    IStatementHandler() { }
    IStatementHandler(const IStatementHandler& ) { }
    IStatementHandler& operator=(const IStatementHandler& ) { return *this; }
};

typedef boost::shared_ptr<IStatementHandler> SharedIStatementHandler;

}
#endif /* GS_ISTATEMENTHANDLER_HPP */
