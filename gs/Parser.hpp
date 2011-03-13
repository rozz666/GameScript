// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_PARSER_HPP
#define GS_PARSER_HPP

#include <boost/shared_ptr.hpp>
#include <string>

namespace gs
{

class Parser
{
public:
    virtual ~Parser() { }
    virtual void parse(const std::string& text) = 0;
protected:
    Parser() { }
    Parser(const Parser& ) { }
    Parser& operator=(const Parser& ) { return *this; }
};

typedef boost::shared_ptr<Parser> SharedParser;

}
#endif /* GS_PARSER_HPP */
