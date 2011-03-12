// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_STATEMENT_HPP
#define GS_STATEMENT_HPP

#include <gs/VariableTable.hpp>
#include <boost/shared_ptr.hpp>

namespace gs
{

class Statement
{
public:
    virtual ~Statement() { }
    virtual void run(SharedVariableTable vt) = 0;
protected:
    Statement() { }
    Statement(const Statement& ) { }
    Statement& operator=(const Statement& ) { return *this; }
};

typedef boost::shared_ptr<Statement> SharedStatement;

}
#endif /* GS_STATEMENT_HPP */
