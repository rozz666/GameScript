// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_VARIABLETABLEMOCK_HPP
#define GS_VARIABLETABLEMOCK_HPP

#include <gs/IVariableTable.hpp>
#include <gmock/gmock.h>

namespace gs
{

struct VariableTableMock : IVariableTable
{
    MOCK_METHOD2(set, void(unsigned, ObjectRef));
    MOCK_METHOD1(get, ObjectRef(unsigned));
};

typedef boost::shared_ptr<VariableTableMock> SharedVariableTableMock;

}
#endif /* GS_VARIABLETABLEMOCK_HPP */
