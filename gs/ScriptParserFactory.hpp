// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_SCRIPTPARSERFACTORY_HPP
#define GS_SCRIPTPARSERFACTORY_HPP

#include <boost/shared_ptr.hpp>
#include <gs/ScriptParser.hpp>

namespace gs
{

class ScriptParserFactory
{
public:
    SharedScriptParser createScriptParser();
};

typedef boost::shared_ptr<ScriptParserFactory> SharedScriptParserFactory;

}
#endif /* GS_SCRIPTPARSERFACTORY_HPP */
