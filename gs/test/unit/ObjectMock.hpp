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

struct ObjectMock : gs::Object
{
    virtual void registerMethods(gs::Registry& r)
    {
        r.method0(&ObjectMock::testMethod1, "testMethod1");
    }

    MOCK_METHOD0(testMethod1, gs::ObjectRef());
    MOCK_METHOD2(testMethod2, gs::ObjectRef(gs::ObjectRef, gs::ObjectRef));
};

typedef boost::shared_ptr<ObjectMock> SharedObjectMock;

}
#endif /* GS_OBJECTMOCK_HPP */
