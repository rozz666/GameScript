// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#include <gs/expr/Object.hpp>
#include <gmock/gmock.h>
#include <gs/test/unit/VariableTableMock.hpp>
#include <gs/test/unit/ObjectStub.hpp>

using namespace testing;

struct gs_expr_Object : testing::Test
{
};

TEST_F(gs_expr_Object, evaluation)
{
    gs::SharedVariableTableMock vt(new gs::VariableTableMock);
    unsigned index = 5;
    gs::expr::Object objExpr(index);
    gs::ObjectRef obj(new gs::ObjectStub);

    EXPECT_CALL(*vt, get(index))
        .WillOnce(Return(obj));
    ASSERT_TRUE(objExpr.eval(vt) == obj);
}
