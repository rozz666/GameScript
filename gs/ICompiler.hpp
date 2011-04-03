// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_ICOMPILER_HPP
#define GS_ICOMPILER_HPP

#include <boost/shared_ptr.hpp>
#include <gs/IScript.hpp>

namespace gs
{

class ICompiler
{
public:
    virtual ~ICompiler() { }
    virtual SharedIScript compile(const std::string& source) = 0;
protected:
    ICompiler() { }
    ICompiler(const ICompiler& ) { }
    ICompiler& operator=(const ICompiler& ) { return *this; }
};

typedef boost::shared_ptr<ICompiler> SharedICompiler;

}
#endif /* GS_ICOMPILER_HPP */
