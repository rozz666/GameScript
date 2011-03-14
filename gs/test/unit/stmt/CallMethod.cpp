// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#include <gs/stmt/CallMethod.hpp>
#include <gmock/gmock.h>
#include <gs/test/unit/ObjectMock.hpp>
#include <gs/test/unit/ObjectStub.hpp>
#include <gs/test/unit/VariableTableMock.hpp>

using namespace testing;

struct gs_stmt_CallMethod : testing::Test
{
};

TEST_F(gs_stmt_CallMethod, callMethod)
{
    unsigned objectIndex = 3;
    std::string methodName = "xyz123";
    gs::ObjectIndices indices;
    indices.push_back(5);
    indices.push_back(6);
    gs::stmt::CallMethod cm(objectIndex, methodName, indices);
    gs::ObjectRef obj(new gs::ObjectMock);
    gs::ObjectRef arg0(new gs::ObjectStub);
    gs::ObjectRef arg1(new gs::ObjectStub);
    gs::SharedVariableTableMock vt(new gs::VariableTableMock);
    gs::CallArgs args;
    args.push_back(arg0);
    args.push_back(arg1);

    EXPECT_CALL(*vt, get(objectIndex))
        .WillOnce(Return(obj));
    EXPECT_CALL(*vt, get(indices[0]))
        .WillOnce(Return(arg0));
    EXPECT_CALL(*vt, get(indices[1]))
        .WillOnce(Return(arg1));

    EXPECT_CALL(static_cast<gs::ObjectMock&>(*obj), callMethod(methodName, args));

    cm.run(vt);
}
