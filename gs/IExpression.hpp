// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_IEXPRESSION_HPP
#define GS_IEXPRESSION_HPP

#include <gs/IObject.hpp>
#include <gs/IVariableTable.hpp>
#include <boost/shared_ptr.hpp>

namespace gs
{

class IExpression
{
public:
    virtual ~IExpression() { }
    virtual ObjectRef eval(SharedIVariableTable vt) = 0;
protected:
    IExpression() { }
    IExpression(const IExpression& ) { }
    IExpression& operator=(const IExpression& ) { return *this; }
};

typedef boost::shared_ptr<IExpression> SharedIExpression;

}
#endif /* GS_IEXPRESSION_HPP */
