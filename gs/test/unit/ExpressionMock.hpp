// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_EXPRESSIONMOCK_HPP
#define GS_EXPRESSIONMOCK_HPP

#include <gs/IExpression.hpp>
#include <gmock/gmock.h>

namespace gs
{

struct ExpressionMock : IExpression
{
    MOCK_METHOD1(eval, ObjectRef(SharedIVariableTable));
};

typedef boost::shared_ptr<ExpressionMock> SharedExpressionMock;

}
#endif /* GS_EXPRESSIONMOCK_HPP */
