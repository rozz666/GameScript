// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_EXPR_OBJECT_HPP
#define GS_EXPR_OBJECT_HPP

#include <boost/shared_ptr.hpp>
#include <gs/Expression.hpp>

namespace gs
{
namespace expr
{

class Object : public Expression
{
public:
    Object(unsigned objectIndex) : objectIndex(objectIndex) { }
    virtual ObjectRef eval(SharedVariableTable vt);
private:
    unsigned objectIndex;
};

typedef boost::shared_ptr<Object> SharedObject;

}
}
#endif /* GS_EXPR_OBJECT_HPP */
