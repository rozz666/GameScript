// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_SCRIPT_HPP
#define GS_SCRIPT_HPP

#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/unordered_map.hpp>
#include <gs/IScript.hpp>

namespace gs
{

class Script : public IScript
{
public:
    virtual ObjectRef callFunction(const std::string& name, const CallArgs& args);
    virtual void addFunction(SharedIFunction f);
private:
    typedef boost::unordered_map<std::string, SharedIFunction> Functions;
    Functions functions_;
};

typedef boost::shared_ptr<Script> SharedScript;

}
#endif /* GS_SCRIPT_HPP */
