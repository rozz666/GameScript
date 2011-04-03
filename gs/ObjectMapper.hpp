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

#include <gs/IObject.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/unordered_map.hpp>
#include <string>

namespace gs
{

template <typename ObjectType>
class ObjectMapper : public IObject
{
public:
    virtual ObjectRef callMethod(const std::string& name, const gs::CallArgs& args)
    {
        return methods_[name]->call(static_cast<ObjectType&>(*this), args);
    }

protected:

    typedef ObjectRef (ObjectType:: *Method0)();
    typedef ObjectRef (ObjectType:: *Method1)(ObjectRef);
    typedef ObjectRef (ObjectType:: *Method2)(ObjectRef, ObjectRef);

    void addMethod(Method0 method, const std::string& name)
    {
        methods_[name] = SharedCaller(new Caller0(method));
    }
    void addMethod(Method1 method, const std::string& name)
    {
        methods_[name] = SharedCaller(new Caller1(method));
    }
    void addMethod(Method2 method, const std::string& name)
    {
        methods_[name] = SharedCaller(new Caller2(method));
    }
private:

    class Caller
    {
    public:
        virtual ~Caller() { }
        virtual ObjectRef call(ObjectType& obj, const gs::CallArgs& args) = 0;
    };

    typedef boost::shared_ptr<Caller> SharedCaller;

    class Caller0 : public Caller
    {
    public:
        Caller0(Method0 m) : m_(m) { }
        virtual ObjectRef call(ObjectType& obj, const gs::CallArgs& args)
        {
            return (obj.*m_)();
        }
    private:
        Method0 m_;
    };

    class Caller1 : public Caller
    {
    public:
        Caller1(Method1 m) : m_(m) { }
        virtual ObjectRef call(ObjectType& obj, const gs::CallArgs& args)
        {
            return (obj.*m_)(args[0]);
        }
    private:
        Method1 m_;
    };

    class Caller2 : public Caller
    {
    public:
        Caller2(Method2 m) : m_(m) { }
        virtual ObjectRef call(ObjectType& obj, const gs::CallArgs& args)
        {
            return (obj.*m_)(args[0], args[1]);
        }
    private:
        Method2 m_;
    };

    boost::unordered_map<std::string, SharedCaller> methods_;
};

}
#endif /* GS_OBJECTMAPPER_HPP */
