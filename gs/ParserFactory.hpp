// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_PARSERFACTORY_HPP
#define GS_PARSERFACTORY_HPP

#include <boost/shared_ptr.hpp>
#include <gs/Parser.hpp>
#include <gs/ScriptInterface.hpp>

namespace gs
{

class ParserFactory
{
public:
    virtual SharedParser createParser(SharedScriptInterface script);
};

typedef boost::shared_ptr<ParserFactory> SharedParserFactory;

}
#endif /* GS_PARSERFACTORY_HPP */
