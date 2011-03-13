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
    gs::CallArgs args;
    args.push_back(gs::ObjectRef(new gs::ObjectStub));
    args.push_back(gs::ObjectRef(new gs::ObjectStub));
    gs::stmt::CallMethod cm(objectIndex, methodName, args);
    gs::ObjectRef obj(new gs::ObjectMock);
    gs::SharedVariableTableMock vt(new gs::VariableTableMock);

    EXPECT_CALL(*vt, get(objectIndex))
        .WillOnce(Return(obj));
    EXPECT_CALL(static_cast<gs::ObjectMock&>(*obj), callMethod(methodName, args));

    cm.run(vt);
}
