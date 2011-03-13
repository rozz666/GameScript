// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_SCRIPTCOMPILERFACTORY_HPP
#define GS_SCRIPTCOMPILERFACTORY_HPP

#include <boost/shared_ptr.hpp>
#include <gs/Compiler.hpp>

namespace gs
{

class ScriptCompilerFactory
{
public:
    virtual SharedCompiler createCompiler();
};

typedef boost::shared_ptr<ScriptCompilerFactory> SharedScriptCompilerFactory;

}
#endif /* GS_SCRIPTCOMPILERFACTORY_HPP */
