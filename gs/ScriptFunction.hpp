// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_SCRIPTFUNCTION_HPP
#define GS_SCRIPTFUNCTION_HPP

#include <gs/Function.hpp>
#include <gs/Statement.hpp>
#include <gs/VariableTable.hpp>
#include <boost/shared_ptr.hpp>

namespace gs
{

class ScriptFunction : public Function
{
public:
    ScriptFunction(const std::string& name, SharedVariableTable vt) : name_(name), vt_(vt) { }
    virtual std::string getName() const;
    virtual void run(const FunctionArgs& args);
    void addStatement(SharedStatement stmt);
private:
    std::string name_;
    SharedVariableTable vt_;
    std::vector<SharedStatement> stmts_;
};

typedef boost::shared_ptr<ScriptFunction> SharedScriptFunction;

}
#endif /* GS_SCRIPTFUNCTION_HPP */
