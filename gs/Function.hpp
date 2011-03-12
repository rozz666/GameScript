// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_FUNCTION_HPP
#define GS_FUNCTION_HPP

#include <gs/Object.hpp>
#include <vector>
#include <string>
#include <boost/shared_ptr.hpp>

namespace gs
{

typedef std::vector<ObjectRef> FunctionArgs;

class Function
{
public:
    virtual ~Function() { }
    virtual std::string getName() const = 0;
    virtual void run(const FunctionArgs& args) = 0;
protected:
    Function() { }
    Function(const Function& ) { }
    Function& operator=(const Function& ) { return *this; }
};

typedef boost::shared_ptr<Function> SharedFunction;

}
#endif /* GS_FUNCTION_HPP */
