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

#include <gs/Function.hpp>
#include <vector>
#include <boost/shared_ptr.hpp>

namespace gs
{

class Script
{
public:
    void callFunction(const std::string& name, const FunctionArgs& args);
    void addFunction(SharedFunction f);
private:
    SharedFunction f;
};

typedef boost::shared_ptr<Script> SharedScript;

}
#endif /* GS_SCRIPT_HPP */
