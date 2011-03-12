// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_OBJECTMAPPER_HPP
#define GS_OBJECTMAPPER_HPP

#include <boost/shared_ptr.hpp>
#include <gs/Object.hpp>

namespace gs
{

template <typename ObjectType>
class ObjectMapper : public Object
{
public:

    virtual void callMethod(const std::string& name, const gs::CallArgs& args) { }
protected:

    void addMethod(ObjectRef (ObjectType:: *method)()) { }
    void addMethod(ObjectRef (ObjectType:: *method)(ObjectRef, ObjectRef)) { }
};

}
#endif /* GS_OBJECTMAPPER_HPP */
