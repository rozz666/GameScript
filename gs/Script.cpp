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

void Script::callFunction(const std::string& name, const gs::FunctionArgs& args)
{
    f->run(args);
}
void Script::addFunction(SharedFunction f)
{
    this->f = f;
}

}
