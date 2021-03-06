// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_STATEMENTHANDLERMOCK_HPP
#define GS_STATEMENTHANDLERMOCK_HPP

#include <gs/IStatementHandler.hpp>
#include <gmock/gmock.h>

namespace gs
{

struct StatementHandlerMock : IStatementHandler
{
    MOCK_METHOD3(functionDef, void(unsigned, const std::string&, const gs::FunctionArgs&));
    MOCK_METHOD1(end, void(unsigned));
    MOCK_METHOD1(eof, void(unsigned));
    MOCK_METHOD4(methodCall, void(unsigned, const std::string&, const std::string&, const FunctionArgs&));
    MOCK_METHOD2(returnStmt, void(unsigned, const std::string&));
    MOCK_METHOD4(returnStmt, void(unsigned, const std::string&, const std::string&, const gs::FunctionArgs&));
    MOCK_METHOD2(variableDef, void(unsigned, const std::string&));
    MOCK_METHOD3(variableDef, void(unsigned, const std::string&, const std::string&));
    MOCK_METHOD5(
        variableDef, void(unsigned, const std::string&, const std::string&, const std::string&, const gs::FunctionArgs&));
};

typedef boost::shared_ptr<StatementHandlerMock> SharedStatementHandlerMock;

}
#endif /* GS_STATEMENTHANDLERMOCK_HPP */
