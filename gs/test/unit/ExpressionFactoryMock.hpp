// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_EXPRESSIONFACTORYMOCK_HPP
#define GS_EXPRESSIONFACTORYMOCK_HPP

#include <gs/ExpressionFactory.hpp>
#include <gmock/gmock.h>

namespace gs
{

struct ExpressionFactoryMock : ExpressionFactory
{
    MOCK_METHOD3(createMethodCall, SharedExpression(unsigned, const std::string&, const ObjectIndices&));
    MOCK_METHOD1(createObject, SharedExpression(unsigned));
};

typedef boost::shared_ptr<ExpressionFactoryMock> SharedExpressionFactoryMock;

}
#endif /* GS_EXPRESSIONFACTORYMOCK_HPP */
