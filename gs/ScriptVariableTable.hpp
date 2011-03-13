// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_SCRIPTVARIABLETABLE_HPP
#define GS_SCRIPTVARIABLETABLE_HPP

#include <boost/shared_ptr.hpp>
#include <gs/VariableTable.hpp>

namespace gs
{

class ScriptVariableTable : public VariableTable
{
public:
    virtual ObjectRef get(unsigned int index);
    virtual void set(unsigned int index, ObjectRef ref);
private:
    ObjectRef object_;
};

typedef boost::shared_ptr<ScriptVariableTable> SharedScriptVariableTable;

}
#endif /* GS_SCRIPTVARIABLETABLE_HPP */
