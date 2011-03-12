// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_SCRIPTPARSER_HPP
#define GS_SCRIPTPARSER_HPP

#include <gs/Script.hpp>
#include <boost/shared_ptr.hpp>

namespace gs
{

class ScriptParser
{
public:
    SharedScript parse(const std::string& text)
    {
        return SharedScript(new Script);
    }
};

typedef boost::shared_ptr<ScriptParser> SharedScriptParser;

}
#endif /* GS_SCRIPTPARSER_HPP */
