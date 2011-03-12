// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#include <gs/ObjectMapper.hpp>
#include <gmock/gmock.h>
#include <gs/test/unit/ObjectStub.hpp>
#include <gs/null.hpp>

using namespace testing;

struct MappedObject : gs::ObjectMapper<MappedObject>
{
    MappedObject()
    {
        addMethod(&MappedObject::method0a, "method0a");
        addMethod(&MappedObject::method0b, "method0b");
        addMethod(&MappedObject::method1, "method1");
        addMethod(&MappedObject::method2, "method2");
    }

    MOCK_METHOD0(method0a, gs::ObjectRef());
    MOCK_METHOD0(method0b, gs::ObjectRef());
    MOCK_METHOD1(method1, gs::ObjectRef(gs::ObjectRef));
    MOCK_METHOD2(method2, gs::ObjectRef(gs::ObjectRef, gs::ObjectRef));
};

struct gs_ObjectMapper : testing::Test
{
    MappedObject mo;
    gs::CallArgs args;
};

TEST_F(gs_ObjectMapper, method0)
{
    EXPECT_CALL(mo, method0a())
        .WillOnce(Return(gs::null));
    mo.callMethod("method0a", args);
    EXPECT_CALL(mo, method0b())
        .WillOnce(Return(gs::null));
    mo.callMethod("method0b", args);
}

TEST_F(gs_ObjectMapper, method1)
{
    args.push_back(gs::ObjectRef(new gs::ObjectStub));

    EXPECT_CALL(mo, method1(args[0]))
        .WillOnce(Return(gs::null));
    mo.callMethod("method1", args);
}

TEST_F(gs_ObjectMapper, method2)
{
    args.push_back(gs::ObjectRef(new gs::ObjectStub));
    args.push_back(gs::ObjectRef(new gs::ObjectStub));

    EXPECT_CALL(mo, method2(args[0], args[1]))
        .WillOnce(Return(gs::null));
    mo.callMethod("method2", args);
}
