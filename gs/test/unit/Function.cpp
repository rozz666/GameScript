// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#include <gs/Function.hpp>
#include <gs/test/unit/StatementMock.hpp>
#include <gs/test/unit/VariableTableMock.hpp>
#include <gs/test/unit/ObjectStub.hpp>
#include <gmock/gmock.h>
#include <gs/null.hpp>

using namespace testing;

struct gs_Function : testing::Test
{
    gs::CallArgs args;
    gs::SharedVariableTableMock vt;
    gs::Function sf;

    gs_Function()
        : vt(new gs::VariableTableMock), sf("", vt) { }
};

TEST_F(gs_Function, name)
{
    std::string name = "abcd";
    gs::Function sf(name, vt);
    ASSERT_EQ(name, sf.getName());
}

TEST_F(gs_Function, addAndRunTwoStatements)
{
    gs::SharedStatementMock st1(new gs::StatementMock);
    gs::SharedStatementMock st2(new gs::StatementMock);
    sf.addStatement(st1);
    sf.addStatement(st2);
    {
        InSequence seq;
        EXPECT_CALL(*st1, run(gs::SharedIVariableTable(vt)))
            .WillOnce(Return(boost::none));
        EXPECT_CALL(*st2, run(gs::SharedIVariableTable(vt)))
            .WillOnce(Return(boost::none));
    }
    ASSERT_TRUE(sf.run(args) == gs::null);
}

TEST_F(gs_Function, twoArgs)
{
    gs::SharedStatementMock st(new gs::StatementMock);
    sf.addStatement(st);
    args.push_back(gs::ObjectRef(new gs::ObjectStub));
    args.push_back(gs::ObjectRef(new gs::ObjectStub));
    {
        InSequence seq;
        EXPECT_CALL(*vt, set(0, args[0]));
        EXPECT_CALL(*vt, set(1, args[1]));
        EXPECT_CALL(*st, run(_))
            .WillOnce(Return(boost::none));
    }
    ASSERT_TRUE(sf.run(args) == gs::null);
}

TEST_F(gs_Function, terminatingStatement)
{
    gs::SharedStatementMock st(new gs::StatementMock);
    sf.addStatement(st);
    gs::ObjectRef obj(new gs::ObjectStub);
    EXPECT_CALL(*st, run(_))
        .WillOnce(Return(obj));
    ASSERT_TRUE(sf.run(gs::CallArgs()) == obj);
}
