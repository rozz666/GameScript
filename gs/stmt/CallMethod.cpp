// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#include <gs/stmt/CallMethod.hpp>
#include <boost/bind.hpp>

namespace gs
{
namespace stmt
{

void CallMethod::run(SharedVariableTable vt)
{
    CallArgs args(indices_.size());
    std::transform(indices_.begin(), indices_.end(), args.begin(), boost::bind(&VariableTable::get, vt, _1));
    vt->get(objectIndex_)->callMethod(methodName_, args);
}

}
}
