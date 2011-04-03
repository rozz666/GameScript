// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_STATEMENTMOCK_HPP
#define GS_STATEMENTMOCK_HPP

#include <gs/IStatement.hpp>
#include <gmock/gmock.h>

namespace gs
{

struct StatementMock : IStatement
{
    MOCK_METHOD1(run, boost::optional<ObjectRef>(SharedIVariableTable));
};

typedef boost::shared_ptr<StatementMock> SharedStatementMock;

}
#endif /* GS_STATEMENTMOCK_HPP */
