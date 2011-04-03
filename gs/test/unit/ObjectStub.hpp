// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_OBJECTSTUB_HPP
#define GS_OBJECTSTUB_HPP

#include <gs/IObject.hpp>
#include <gmock/gmock.h>

namespace gs
{

struct ObjectStub : gs::IObject
{
    virtual ObjectRef callMethod(const std::string&, const gs::CallArgs&) { return ObjectRef(); }
};

}
#endif /* GS_OBJECTSTUB_HPP */
