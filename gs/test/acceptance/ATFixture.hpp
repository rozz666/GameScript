// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_ATFIXTURE_HPP
#define GS_ATFIXTURE_HPP
#include <gs/Object.hpp>
#include <gs/ScriptCompilerFactory.hpp>
#include <gs/test/acceptance/MappedObjectMock.hpp>
#include <gs/test/defaultValues.hpp>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <gmock/gmock.h>

namespace gs
{

struct ATFixture : testing::Test
{
    gs::ObjectRef obj;
    gs::CallArgs args;

    ATFixture() : obj(new gs::MappedObjectMock)
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

}

#endif /* GS_ATFIXTURE_HPP */
