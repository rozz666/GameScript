// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#include <gs/ExpressionFactory.hpp>
#include <gs/expr/Object.hpp>
#include <gs/expr/MethodCall.hpp>

namespace gs
{

SharedIExpression ExpressionFactory::createObject(unsigned objectIndex)
{
    return SharedIExpression(new expr::Object(objectIndex));
}

SharedIExpression ExpressionFactory::createMethodCall(
    unsigned objectIndex, const std::string& methodName, const ObjectIndices& indices)
{
    return SharedIExpression(new expr::MethodCall(objectIndex, methodName, indices));
}

}
