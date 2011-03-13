// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#include <gs/ScriptVariableTable.hpp>
#include <gs/null.hpp>

namespace gs
{

gs::ObjectRef ScriptVariableTable::get(unsigned int index)
{
    return objects_[index];
}

void ScriptVariableTable::set(unsigned int index, ObjectRef ref)
{
    objects_[index] = ref;
}

}
