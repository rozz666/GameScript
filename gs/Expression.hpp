// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_EXPRESSION_HPP
#define GS_EXPRESSION_HPP

#include <boost/shared_ptr.hpp>
#include <gs/Object.hpp>
#include <gs/VariableTable.hpp>

namespace gs
{

class Expression
{
public:
    virtual ~Expression() { }
    virtual ObjectRef eval(SharedVariableTable vt) = 0;
protected:
    Expression() { }
    Expression(const Expression& ) { }
    Expression& operator=(const Expression& ) { return *this; }
};

typedef boost::shared_ptr<Expression> SharedExpression;

}
#endif /* GS_EXPRESSION_HPP */
