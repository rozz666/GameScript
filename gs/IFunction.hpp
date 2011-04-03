// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_IFUNCTION_HPP
#define GS_IFUNCTION_HPP

#include <gs/IObject.hpp>
#include <gs/IStatement.hpp>
#include <vector>
#include <string>
#include <boost/shared_ptr.hpp>

namespace gs
{

class IFunction
{
public:
    virtual ~IFunction() { }
    virtual std::string getName() const = 0;
    virtual ObjectRef run(const CallArgs& args) = 0;
    virtual void addStatement(SharedIStatement stmt) = 0;
protected:
    IFunction() { }
    IFunction(const IFunction& ) { }
    IFunction& operator=(const IFunction& ) { return *this; }
};

typedef boost::shared_ptr<IFunction> SharedIFunction;

}
#endif /* GS_IFUNCTION_HPP */
