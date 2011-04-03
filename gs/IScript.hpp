// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_ISCRIPT_HPP
#define GS_ISCRIPT_HPP

#include <gs/IFunction.hpp>
#include <boost/shared_ptr.hpp>

namespace gs
{

class IScript
{
public:
    virtual ~IScript() { }
    virtual void addFunction(SharedIFunction f) = 0;
    virtual ObjectRef callFunction(const std::string& name, const CallArgs& args) = 0;
protected:
    IScript() { }
    IScript(const IScript& ) { }
    IScript& operator=(const IScript& ) { return *this; }
};

typedef boost::shared_ptr<IScript> SharedIScript;

}
#endif /* GS_ISCRIPT_HPP */
