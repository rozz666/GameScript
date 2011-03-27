// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#include <gs/stmt/Return.hpp>
#include <gmock/gmock.h>
#include <gs/test/unit/VariableTableMock.hpp>
#include <gs/test/unit/ObjectStub.hpp>
#include <gs/test/unit/ExpressionMock.hpp>

using namespace testing;

struct gs_stmt_Return : testing::Test
{
    gs::SharedVariableTableMock vt;
    gs::ObjectRef obj;

    gs_stmt_Return() : vt(new gs::VariableTableMock), obj(new gs::ObjectStub) { }
};

TEST_F(gs_stmt_Return, returnExpression)
{
    gs::SharedExpressionMock expr(new gs::ExpressionMock);
    gs::stmt::Return ret(expr);

    EXPECT_CALL(*expr, eval(gs::SharedVariableTable(vt)))
        .WillOnce(Return(obj));
    ASSERT_TRUE(ret.run(vt) == obj);
}
