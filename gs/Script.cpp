// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#include <gs/Script.hpp>

namespace gs
{

ObjectRef Script::callFunction(const std::string& name, const gs::CallArgs& args)
{
    return functions_[name]->run(args);
}

void Script::addFunction(SharedIFunction f)
{
    functions_[f->getName()] = f;
}

}
