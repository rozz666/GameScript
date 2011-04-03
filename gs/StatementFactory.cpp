// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#include <gs/StatementFactory.hpp>
#include <gs/stmt/CallMethod.hpp>
#include <gs/stmt/Return.hpp>

namespace gs
{

SharedIStatement StatementFactory::createCallMethod(
    unsigned int objectIndex, const std::string& methodName, const gs::ObjectIndices& indices)
{
    return SharedIStatement(new stmt::CallMethod(objectIndex, methodName, indices));
}

SharedIStatement StatementFactory::createReturn(SharedIExpression expr)
{
    return SharedIStatement(new stmt::Return(expr));
}

}
