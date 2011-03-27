// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_STMT_RETURN_HPP
#define GS_STMT_RETURN_HPP

#include <boost/shared_ptr.hpp>
#include <gs/Statement.hpp>
#include <gs/Expression.hpp>

namespace gs
{
namespace stmt
{

class Return : public Statement
{
public:
    Return(unsigned objectIndex);
    Return(SharedExpression expr) : expr(expr) { }
    virtual boost::optional<ObjectRef> run(SharedVariableTable vt);
private:
    SharedExpression expr;
};

typedef boost::shared_ptr<Return> SharedReturn;

}
}
#endif /* GS_STMT_RETURN_HPP */
