// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_STATEMENTSTUB_HPP
#define GS_STATEMENTSTUB_HPP

#include <gs/Statement.hpp>

namespace gs
{

struct StatementStub : Statement
{
    virtual void run(SharedVariableTable vt) { }
};

typedef boost::shared_ptr<StatementStub> SharedStatementStub;

}
#endif /* GS_STATEMENTSTUB_HPP */
