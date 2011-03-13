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

#include <boost/shared_ptr.hpp>
#include <gs/ScriptInterface.hpp>

namespace gs
{

class Compiler
{
public:
    virtual ~Compiler() { }
    virtual SharedScriptInterface compile(const std::string& source) = 0;
protected:
    Compiler() { }
    Compiler(const Compiler& ) { }
    Compiler& operator=(const Compiler& ) { return *this; }
};

typedef boost::shared_ptr<Compiler> SharedCompiler;

}
#endif /* GS_COMPILER_HPP */
