// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_REGISTRY_HPP
#define GS_REGISTRY_HPP

#include <gs/Object.hpp>
#include <boost/function.hpp>
#include <string>
#include <boost/shared_ptr.hpp>

namespace gs
{

class ObjectMethodWrapper
{
public:

    template <typename ObjectType>
    ObjectMethodWrapper(ObjectRef (ObjectType:: *method)()) { }
};

class Registry
{
public:
    virtual ~Registry() { }
    virtual void method0(ObjectMethodWrapper, const std::string& name) = 0;
protected:
    Registry() { }
    Registry(const Registry& ) { }
    Registry& operator=(const Registry& ) { return *this; }
};

typedef boost::shared_ptr<Registry> SharedRegistry;

}
#endif /* GS_REGISTRY_HPP */
