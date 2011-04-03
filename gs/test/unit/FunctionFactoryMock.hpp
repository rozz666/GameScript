// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_FUNCTIONFACTORYMOCK_HPP
#define GS_FUNCTIONFACTORYMOCK_HPP

#include <gs/FunctionFactory.hpp>
#include <gmock/gmock.h>

namespace gs
{

struct FunctionFactoryMock : FunctionFactory
{
    MOCK_METHOD1(createFunction, SharedIFunction(const std::string&));
};

typedef boost::shared_ptr<FunctionFactoryMock> SharedFunctionFactoryMock;

}
#endif /* GS_FUNCTIONFACTORYMOCK_HPP */
