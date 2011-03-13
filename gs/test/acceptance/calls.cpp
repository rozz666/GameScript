// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#include <gs/Object.hpp>
#include <gs/null.hpp>
#include <gs/test/unit/MappedObjectMock.hpp>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <gmock/gmock.h>
#include <gs/test/unit/ObjectStub.hpp>
#include <gs/ScriptCompilerFactory.hpp>
using namespace testing;

struct Calls : testing::Test
{
    gs::ObjectRef obj;
    gs::CallArgs args;

    Calls() : obj(new gs::MappedObjectMock)
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

    gs::SharedScriptInterface loadScript(const std::string& path)
    {
        gs::SharedCompiler compiler = gs::ScriptCompilerFactory().createCompiler();
        return compiler->compile(loadFile("gs/test/acceptance/scripts/" + path));
    }
};

TEST_F(Calls, callNoArgs)
{
    gs::SharedScriptInterface s = loadScript("callTest1.gs");
    EXPECT_CALL(static_cast<gs::MappedObjectMock&>(*obj), testMethod1())
        .WillOnce(Return(gs::null));
    s->callFunction("test1", args);
}

TEST_F(Calls, callTwoArgs)
{
    gs::SharedScriptInterface s = loadScript("callTest2.gs");
    args.push_back(gs::ObjectRef(new gs::ObjectStub));
    args.push_back(gs::ObjectRef(new gs::ObjectStub));
    EXPECT_CALL(static_cast<gs::MappedObjectMock&>(*obj), testMethod2(args[1], args[2]))
        .WillOnce(Return(gs::null));
    s->callFunction("test2", args);
}