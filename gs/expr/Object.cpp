// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#include <gs/expr/Object.hpp>

namespace gs
{
namespace expr
{

gs::ObjectRef Object::eval(gs::SharedIVariableTable vt)
{
    return vt->get(objectIndex);
}

}
}
