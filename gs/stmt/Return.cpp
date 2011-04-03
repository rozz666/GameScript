// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#include <gs/stmt/Return.hpp>
#include <gs/expr/Object.hpp>

namespace gs
{
namespace stmt
{
boost::optional<ObjectRef> Return::run(SharedIVariableTable vt)
{
    return expr->eval(vt);
}

}
}
