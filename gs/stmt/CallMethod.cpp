// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#include <gs/stmt/CallMethod.hpp>

namespace gs
{
namespace stmt
{

void CallMethod::run(SharedVariableTable vt)
{
    vt->get(objectIndex_)->callMethod(methodName_, args_);
}

}
}
