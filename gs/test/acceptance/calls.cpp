// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#include <gs/Object.hpp>
#include <gs/Registry.hpp>
#include <gs/ScriptParser.hpp>
#include <gs/null.hpp>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <gmock/gmock.h>
using namespace testing;

struct ObjectMock : gs::Object
{
    virtual void registerMethods(gs::Registry& r)
    {
        r.method0(&ObjectMock::testMethod1, "testMethod1");
    }

    MOCK_METHOD0(testMethod1, gs::ObjectRef());
    MOCK_METHOD2(testMethod2, gs::ObjectRef(gs::ObjectRef, gs::ObjectRef));
};

struct ObjectStub : gs::Object
{
    virtual void registerMethods(gs::Registry& ) { }
};

struct Calls : testing::Test
{
    gs::ObjectRef obj;
    gs::FunctionArgs args;

    Calls() : obj(new ObjectMock)
    {
        args.push_back(obj);
    }

    std::string loadFile(const std::string& path)
    {
        std::ifstream f(path.c_str());
        EXPECT_TRUE(f.is_open());
        std::string text;
        std::copy(std::istreambuf_iterator<char>(f), std::istreambuf_iterator<char>(), std::back_inserter(text));
        return text;
    }

    gs::SharedScript loadScript(const std::string& path)
    {
        gs::ScriptParser parser;
        return parser.parse(loadFile("gs/test/acceptance/scripts/" + path));
    }
};

TEST_F(Calls, callNoArgs)
{
    gs::SharedScript s = loadScript("callTest1.gs");
    EXPECT_CALL(static_cast<ObjectMock&>(*obj), testMethod1())
        .WillOnce(Return(gs::null));
    s->callFunction("test1", args);
}

TEST_F(Calls, callTwoArgs)
{
    gs::SharedScript s = loadScript("callTest2.gs");
    args.push_back(gs::ObjectRef(new ObjectStub));
    args.push_back(gs::ObjectRef(new ObjectStub));
    EXPECT_CALL(static_cast<ObjectMock&>(*obj), testMethod2(args[1], args[2]))
        .WillOnce(Return(gs::null));
    s->callFunction("test2", args);
}