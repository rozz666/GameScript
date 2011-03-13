// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_STATEMENTHANDLERFACTORYMOCK_HPP
#define GS_STATEMENTHANDLERFACTORYMOCK_HPP

#include <gs/StatementHandlerFactory.hpp>
#include <gmock/gmock.h>

namespace gs
{

struct StatementHandlerFactoryMock : StatementHandlerFactory
{
    MOCK_METHOD1(createStatementHandler, gs::SharedStatementHandler(gs::SharedScriptInterface));
};

typedef boost::shared_ptr<StatementHandlerFactoryMock> SharedStatementHandlerFactoryMock;

}
#endif /* GS_STATEMENTHANDLERFACTORYMOCK_HPP */
