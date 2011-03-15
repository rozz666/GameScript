// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_OBJECT_HPP
#define GS_OBJECT_HPP

#include <boost/shared_ptr.hpp>
#include <vector>

namespace gs
{

class Object;

typedef boost::shared_ptr<Object> SharedObject;
typedef SharedObject ObjectRef;

typedef std::vector<ObjectRef> CallArgs;

class Object
{
public:
    virtual ~Object() { }
    virtual ObjectRef callMethod(const std::string& name, const CallArgs& args) = 0;
protected:
    Object() { }
    Object(const Object& ) { }
    Object& operator=(const Object& ) { return *this; }
};


}
#endif /* GS_OBJECT_HPP */
