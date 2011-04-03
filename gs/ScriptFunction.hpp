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

#include <gs/IFunction.hpp>
#include <gs/IStatement.hpp>
#include <gs/IVariableTable.hpp>
#include <boost/shared_ptr.hpp>

namespace gs
{

class ScriptFunction : public IFunction
{
public:
    ScriptFunction(const std::string& name, SharedIVariableTable vt) : name_(name), vt_(vt) { }
    virtual std::string getName() const;
    virtual ObjectRef run(const CallArgs& args);
    virtual void addStatement(SharedIStatement stmt);
private:
    std::string name_;
    SharedIVariableTable vt_;
    std::vector<SharedIStatement> stmts_;
    void setArgs(const CallArgs& args);
    ObjectRef runStatements();
};

typedef boost::shared_ptr<ScriptFunction> SharedScriptFunction;

}
#endif /* GS_SCRIPTFUNCTION_HPP */
