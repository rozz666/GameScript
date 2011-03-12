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

#include <boost/shared_ptr.hpp>

namespace gs
{

class VariableTable
{
public:
    virtual ~VariableTable() { }
protected:
    VariableTable() { }
    VariableTable(const VariableTable& ) { }
    VariableTable& operator=(const VariableTable& ) { return *this; }
};

typedef boost::shared_ptr<VariableTable> SharedVariableTable;

}
#endif /* GS_VARIABLETABLE_HPP */