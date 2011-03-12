// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_STMT_CALLMETHOD_HPP
#define GS_STMT_CALLMETHOD_HPP

#include <gs/Statement.hpp>
#include <string>
#include <boost/shared_ptr.hpp>

namespace gs
{
namespace stmt
{

class CallMethod : public Statement
{
public:
    CallMethod(unsigned objectIndex, const std::string& methodName, const CallArgs& args)
        : objectIndex_(objectIndex), methodName_(methodName), args_(args) { }
    virtual void run(SharedVariableTable vt);
private:
    unsigned objectIndex_;
    std::string methodName_;
    CallArgs args_;
};

typedef boost::shared_ptr<CallMethod> SharedCallMethod;

}
}
#endif /* GS_STMT_CALLMETHOD_HPP */
