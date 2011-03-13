// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#include <gs/ScriptVariableTable.hpp>
#include <gmock/gmock.h>
#include <gs/test/unit/ObjectStub.hpp>

using namespace testing;

struct gs_ScriptVariableTable : testing::Test
{
};

TEST_F(gs_ScriptVariableTable, testGetSet)
{
    gs::ScriptVariableTable vt;
    gs::ObjectRef obj(new gs::ObjectStub);

    vt.set(0, obj);
    ASSERT_TRUE(vt.get(0) == obj);
}
