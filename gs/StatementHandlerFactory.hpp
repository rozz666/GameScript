// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_STATEMENTHANDLERFACTORY_HPP
#define GS_STATEMENTHANDLERFACTORY_HPP

#include <boost/shared_ptr.hpp>
#include <gs/StatementHandler.hpp>
#include <gs/ScriptInterface.hpp>

namespace gs
{

class StatementHandlerFactory
{
public:
    virtual SharedStatementHandler createStatementHandler(SharedScriptInterface script) = 0;
};

typedef boost::shared_ptr<StatementHandlerFactory> SharedStatementHandlerFactory;

}
#endif /* GS_STATEMENTHANDLERFACTORY_HPP */
