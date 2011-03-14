// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_STATEMENTFACTORYMOCK_HPP
#define GS_STATEMENTFACTORYMOCK_HPP

#include <gs/StatementFactory.hpp>
#include <gmock/gmock.h>

namespace gs
{

struct StatementFactoryMock : StatementFactory
{
    MOCK_METHOD3(createCallMethod, SharedStatement(unsigned, const std::string&, const gs::ObjectIndices& ));
};

typedef boost::shared_ptr<StatementFactoryMock> SharedStatementFactoryMock;

}
#endif /* GS_STATEMENTFACTORYMOCK_HPP */
