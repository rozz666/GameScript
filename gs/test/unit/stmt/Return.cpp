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

using namespace testing;

struct gs_stmt_Return : testing::Test
{
};

TEST_F(gs_stmt_Return, returnObject)
{
    gs::SharedVariableTableMock vt(new gs::VariableTableMock);
    unsigned objectIndex = 5;
    gs::ObjectRef obj(new gs::ObjectStub);
    gs::stmt::Return ret(objectIndex);

    EXPECT_CALL(*vt, get(objectIndex))
        .WillOnce(Return(obj));
    ASSERT_TRUE(ret.run(vt) == obj);
}
