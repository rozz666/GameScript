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

#include <gs/IExpression.hpp>
#include <gs/IStatement.hpp>
#include <boost/shared_ptr.hpp>

namespace gs
{
namespace expr
{

class MethodCall : public IExpression
{
public:
    MethodCall(unsigned objectIndex, const std::string& methodName, const ObjectIndices& indices)
        : objectIndex_(objectIndex), methodName_(methodName), indices_(indices) { }
    virtual ObjectRef eval(SharedIVariableTable vt);
private:
    unsigned objectIndex_;
    std::string methodName_;
    ObjectIndices indices_;
};

typedef boost::shared_ptr<MethodCall> SharedMethodCall;

}
}
#endif /* GS_EXPR_METHODCALL_HPP */
