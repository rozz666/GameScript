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

#include <gs/IStatement.hpp>

namespace gs
{

struct StatementStub : IStatement
{
    virtual boost::optional<ObjectRef> run(SharedIVariableTable vt) { return boost::none; }
};

typedef boost::shared_ptr<StatementStub> SharedStatementStub;

}
#endif /* GS_STATEMENTSTUB_HPP */
