// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_EXPRESSIONFACTORY_HPP
#define GS_EXPRESSIONFACTORY_HPP

#include <boost/shared_ptr.hpp>
#include <gs/Expression.hpp>
#include <gs/Statement.hpp>

namespace gs
{

class ExpressionFactory
{
public:
    virtual SharedExpression createObject(unsigned objectIndex);
    virtual SharedExpression createMethodCall(
        unsigned objectIndex, const std::string& methodName, const ObjectIndices& indices);
};

typedef boost::shared_ptr<ExpressionFactory> SharedExpressionFactory;

}
#endif /* GS_EXPRESSIONFACTORY_HPP */
