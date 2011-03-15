// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_OBJECTMOCK_HPP
#define GS_OBJECTMOCK_HPP

#include <gs/Object.hpp>
#include <gmock/gmock.h>

namespace gs
{

struct ObjectMock : Object
{
    MOCK_METHOD2(callMethod, ObjectRef(const std::string&, const gs::CallArgs&));
};

typedef boost::shared_ptr<ObjectMock> SharedObjectMock;

}
#endif /* GS_OBJECTMOCK_HPP */
