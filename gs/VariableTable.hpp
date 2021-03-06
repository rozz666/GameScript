// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_VARIABLETABLE_HPP
#define GS_VARIABLETABLE_HPP

#include <gs/IVariableTable.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/unordered_map.hpp>

namespace gs
{

class VariableTable : public IVariableTable
{
public:
    virtual ObjectRef get(unsigned int index);
    virtual void set(unsigned int index, ObjectRef ref);
private:
    boost::unordered_map<unsigned, ObjectRef> objects_;
};

typedef boost::shared_ptr<VariableTable> SharedVariableTable;

}
#endif /* GS_VARIABLETABLE_HPP */
