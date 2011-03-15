// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_EXPR_METHODCALL_HPP
#define GS_EXPR_METHODCALL_HPP

#include <boost/shared_ptr.hpp>
#include <gs/Expression.hpp>
#include <gs/Statement.hpp>

namespace gs
{
namespace expr
{

class MethodCall : public Expression
{
public:
    MethodCall(unsigned objectIndex, const std::string& methodName, const ObjectIndices& indices)
        : objectIndex_(objectIndex), methodName_(methodName), indices_(indices) { }
    virtual ObjectRef eval(SharedVariableTable vt);
private:
    unsigned objectIndex_;
    std::string methodName_;
    ObjectIndices indices_;
};

typedef boost::shared_ptr<MethodCall> SharedMethodCall;

}
}
#endif /* GS_EXPR_METHODCALL_HPP */
