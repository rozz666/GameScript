// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_COMPILER_HPP
#define GS_COMPILER_HPP

#include <gs/ICompiler.hpp>
#include <gs/ScriptFactory.hpp>
#include <gs/ParserFactory.hpp>
#include <boost/shared_ptr.hpp>

namespace gs
{

class Compiler : public ICompiler
{
public:
    Compiler(SharedScriptFactory scriptFactory, SharedParserFactory parserFactory)
        : scriptFactory(scriptFactory), parserFactory(parserFactory) { }
    virtual SharedIScript compile(const std::string& source);
private:
    SharedScriptFactory scriptFactory;
    SharedParserFactory parserFactory;
};

typedef boost::shared_ptr<Compiler> SharedCompiler;

}
#endif /* GS_COMPILER_HPP */
