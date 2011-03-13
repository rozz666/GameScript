// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_FUNCTIONFACTORY_HPP
#define GS_FUNCTIONFACTORY_HPP

#include <gs/ScriptFunction.hpp>
#include <boost/shared_ptr.hpp>
#include <gs/ScriptVariableTable.hpp>

namespace gs
{

class FunctionFactory
{
public:
    virtual SharedFunction createFunction(const std::string& name);
};

typedef boost::shared_ptr<FunctionFactory> SharedFunctionFactory;

}
#endif /* GS_FUNCTIONFACTORY_HPP */
