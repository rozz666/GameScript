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
#include <boost/foreach.hpp>
#include <gs/null.hpp>

namespace gs
{

std::string ScriptFunction::getName() const
{
    return name_;
}

ObjectRef ScriptFunction::run(const gs::CallArgs& args)
{
    setArgs(args);
    return runStatements();
}

void ScriptFunction::addStatement(gs::SharedIStatement stmt)
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

ObjectRef ScriptFunction::runStatements()
{
    BOOST_FOREACH(gs::SharedIStatement st, stmts_)
    {
        if (boost::optional<ObjectRef> ret = st->run(vt_))
        {
            return *ret;
        }
    }
    return ObjectRef();
}

}
