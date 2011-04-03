// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_ISTATEMENT_HPP
#define GS_ISTATEMENT_HPP

#include <gs/IVariableTable.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/optional.hpp>

namespace gs
{

typedef std::vector<unsigned> ObjectIndices;

class IStatement
{
public:
    virtual ~IStatement() { }
    virtual boost::optional<ObjectRef> run(SharedIVariableTable vt) = 0;
protected:
    IStatement() { }
    IStatement(const IStatement& ) { }
    IStatement& operator=(const IStatement& ) { return *this; }
};

typedef boost::shared_ptr<IStatement> SharedIStatement;

}
#endif /* GS_ISTATEMENT_HPP */
