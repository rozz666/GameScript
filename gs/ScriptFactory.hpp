// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_SCRIPTFACTORY_HPP
#define GS_SCRIPTFACTORY_HPP

#include <boost/shared_ptr.hpp>
#include <gs/IScript.hpp>

namespace gs
{

class ScriptFactory
{
public:
    virtual SharedIScript createScript();
};

typedef boost::shared_ptr<ScriptFactory> SharedScriptFactory;

}
#endif /* GS_SCRIPTFACTORY_HPP */
