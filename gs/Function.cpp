// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#include <gs/Function.hpp>
#include <algorithm>
#include <boost/bind.hpp>
#include <boost/foreach.hpp>
#include <gs/null.hpp>

namespace gs
{

std::string Function::getName() const
{
    return name_;
}

ObjectRef Function::run(const gs::CallArgs& args)
{
    setArgs(args);
    return runStatements();
}

void Function::addStatement(gs::SharedIStatement stmt)
{
    stmts_.push_back(stmt);
}
void Function::setArgs(const gs::CallArgs& args)
{
    for (unsigned i = 0; i != args.size(); ++i)
    {
        vt_->set(i, args[i]);
    }
}

ObjectRef Function::runStatements()
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
