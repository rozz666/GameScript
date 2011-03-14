// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_FUNCTIONMOCK_HPP
#define GS_FUNCTIONMOCK_HPP

#include <gs/Function.hpp>
#include <gmock/gmock.h>

namespace gs
{

struct FunctionMock : Function
{
    MOCK_CONST_METHOD0(getName, std::string());
    MOCK_METHOD1(run, void(const CallArgs& ));
    MOCK_METHOD1(addStatement, void(SharedStatement));
};

typedef boost::shared_ptr<FunctionMock> SharedFunctionMock;

}
#endif /* GS_FUNCTIONMOCK_HPP */
