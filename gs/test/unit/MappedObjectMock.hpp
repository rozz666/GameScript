// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_MAPPEDOBJECTMOCK_HPP
#define GS_MAPPEDOBJECTMOCK_HPP

#include <gs/ObjectMapper.hpp>
#include <gmock/gmock.h>

namespace gs
{

struct MappedObjectMock : gs::ObjectMapper<MappedObjectMock>
{
    MappedObjectMock()
    {
        addMethod(&MappedObjectMock::testMethod1);
        addMethod(&MappedObjectMock::testMethod2);
    }

    MOCK_METHOD0(testMethod1, gs::ObjectRef());
    MOCK_METHOD2(testMethod2, gs::ObjectRef(gs::ObjectRef, gs::ObjectRef));
};

typedef boost::shared_ptr<MappedObjectMock> SharedMappedObjectMock;

}
#endif /* GS_MAPPEDOBJECTMOCK_HPP */
