// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#include <gs/ScriptFunction.hpp>
#include <algorithm>
#include <boost/bind.hpp>

namespace gs
{

std::string ScriptFunction::getName() const
{
    return name_;
}

void ScriptFunction::run(const gs::CallArgs& args)
{
    setArgs(args);
    runStatements();
}

void ScriptFunction::addStatement(gs::SharedStatement stmt)
{
    stmts_.push_back(stmt);
}
void ScriptFunction::setArgs(const gs::CallArgs& args)
{
    for (unsigned i = 0; i != args.size(); ++i)
    {
        vt_->set(i, args[i]);
    }
}

void ScriptFunction::runStatements()
{
    std::for_each(stmts_.begin(), stmts_.end(), boost::bind(&Statement::run, _1, vt_));
}

}
