// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_SCRIPTINTERFACE_HPP
#define GS_SCRIPTINTERFACE_HPP

#include <gs/Function.hpp>
#include <boost/shared_ptr.hpp>

namespace gs
{

class ScriptInterface
{
public:
    virtual ~ScriptInterface() { }
    virtual void addFunction(SharedFunction f) = 0;
    virtual ObjectRef callFunction(const std::string& name, const CallArgs& args) = 0;
protected:
    ScriptInterface() { }
    ScriptInterface(const ScriptInterface& ) { }
    ScriptInterface& operator=(const ScriptInterface& ) { return *this; }
};

typedef boost::shared_ptr<ScriptInterface> SharedScriptInterface;

}
#endif /* GS_SCRIPTINTERFACE_HPP */
