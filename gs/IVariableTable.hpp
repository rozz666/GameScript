// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_IVARIABLETABLE_HPP
#define GS_IVARIABLETABLE_HPP

#include <boost/shared_ptr.hpp>
#include <gs/IObject.hpp>

namespace gs
{

class IVariableTable
{
public:
    virtual ~IVariableTable() { }
    virtual void set(unsigned index, ObjectRef ref) = 0;
    virtual ObjectRef get(unsigned index) = 0;
protected:
    IVariableTable() { }
    IVariableTable(const IVariableTable& ) { }
    IVariableTable& operator=(const IVariableTable& ) { return *this; }
};

typedef boost::shared_ptr<IVariableTable> SharedIVariableTable;

}
#endif /* GS_IVARIABLETABLE_HPP */
