// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_COMPILERFACTORY_HPP
#define GS_COMPILERFACTORY_HPP

#include <gs/ICompiler.hpp>
#include <boost/shared_ptr.hpp>

namespace gs
{

class CompilerFactory
{
public:
    virtual SharedICompiler createCompiler();
};

typedef boost::shared_ptr<CompilerFactory> SharedCompilerFactory;

}
#endif /* GS_COMPILERFACTORY_HPP */
