// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_STATEMENTFACTORY_HPP
#define GS_STATEMENTFACTORY_HPP

#include <gs/Statement.hpp>
#include <boost/shared_ptr.hpp>

namespace gs
{

class StatementFactory
{
public:
    virtual SharedStatement createCallMethod(
        unsigned objectIndex, const std::string& methodName, const ObjectIndices& indices);
    virtual SharedStatement createReturn(unsigned objectIndex);
};

typedef boost::shared_ptr<StatementFactory> SharedStatementFactory;

}
#endif /* GS_STATEMENTFACTORY_HPP */
