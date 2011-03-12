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

namespace gs
{

class Registry;
class Object
{
public:
    virtual ~Object() { }
    virtual void registerMethods(gs::Registry& r) = 0;
protected:
    Object() { }
    Object(const Object& ) { }
    Object& operator=(const Object& ) { return *this; }
};

typedef boost::shared_ptr<Object> SharedObject;
typedef SharedObject ObjectRef;

}
#endif /* GS_OBJECT_HPP */
