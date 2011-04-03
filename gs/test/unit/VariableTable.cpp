// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#include <gs/VariableTable.hpp>
#include <gs/test/unit/ObjectStub.hpp>
#include <gmock/gmock.h>

using namespace testing;

struct gs_ScriptVariableTable : testing::Test
{
};

TEST_F(gs_ScriptVariableTable, testGetSet)
{
    gs::VariableTable vt;
    gs::ObjectRef obj1(new gs::ObjectStub);
    gs::ObjectRef obj2(new gs::ObjectStub);

    vt.set(0, obj1);
    vt.set(7, obj2);
    ASSERT_TRUE(vt.get(0) == obj1);
    ASSERT_TRUE(vt.get(7) == obj2);
}
