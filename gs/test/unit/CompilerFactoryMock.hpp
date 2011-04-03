// GameScript
//
// Copyright (c) 2011 Rafal Przywarski
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef GS_COMPILERFACTORYMOCK_HPP
#define GS_COMPILERFACTORYMOCK_HPP

#include <gs/CompilerFactory.hpp>
#include <gmock/gmock.h>

namespace gs
{

struct CompilerFactoryMock : CompilerFactory
{
};

typedef boost::shared_ptr<CompilerFactoryMock> SharedCompilerFactoryMock;

}
#endif /* GS_COMPILERFACTORYMOCK_HPP */
