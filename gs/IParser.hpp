// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_IPARSER_HPP
#define GS_IPARSER_HPP

#include <boost/shared_ptr.hpp>
#include <string>

namespace gs
{

class IParser
{
public:
    virtual ~IParser() { }
    virtual void parse(const std::string& text) = 0;
protected:
    IParser() { }
    IParser(const IParser& ) { }
    IParser& operator=(const IParser& ) { return *this; }
};

typedef boost::shared_ptr<IParser> SharedIParser;

}
#endif /* GS_IPARSER_HPP */
