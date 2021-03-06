// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#include <gs/FunctionFactory.hpp>

namespace gs
{

SharedIFunction FunctionFactory::createFunction(const std::string& name)
{
    SharedIVariableTable vt(new VariableTable);
    return SharedIFunction(new Function(name, vt));
}

}
