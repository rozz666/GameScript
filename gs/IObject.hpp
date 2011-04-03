// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_IOBJECT_HPP
#define GS_IOBJECT_HPP

#include <boost/shared_ptr.hpp>
#include <vector>

namespace gs
{

class IObject;

typedef boost::shared_ptr<IObject> SharedIObject;
typedef SharedIObject ObjectRef;

typedef std::vector<ObjectRef> CallArgs;

class IObject
{
public:
    virtual ~IObject() { }
    virtual ObjectRef callMethod(const std::string& name, const CallArgs& args) = 0;
protected:
    IObject() { }
    IObject(const IObject& ) { }
    IObject& operator=(const IObject& ) { return *this; }
};


}
#endif /* GS_IOBJECT_HPP */
