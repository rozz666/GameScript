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

#include <gs/IStatement.hpp>
#include <gs/IExpression.hpp>
#include <boost/shared_ptr.hpp>

namespace gs
{
namespace stmt
{

class Return : public IStatement
{
public:
    Return(SharedIExpression expr) : expr(expr) { }
    virtual boost::optional<ObjectRef> run(SharedIVariableTable vt);
private:
    SharedIExpression expr;
};

typedef boost::shared_ptr<Return> SharedReturn;

}
}
#endif /* GS_STMT_RETURN_HPP */
