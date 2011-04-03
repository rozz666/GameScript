project(gamescript)

cmake_minimum_required(VERSION 2.8)

include_directories("." "gmock-1.5.0/fused-src" "dicpp/include")

set(CMAKE_CXX_FLAGS "-Wall")

add_library(
    gmock STATIC
    gmock-1.5.0/fused-src/gmock-gtest-all.cc
)

add_library(
    dicpp STATIC
    dicpp/lib/src/type_info.cpp
    dicpp/lib/src/scope.cpp
    dicpp/lib/src/scopes
    dicpp/lib/src/scopes/thread_local_singleton.cpp
    dicpp/lib/src/scopes/no_scope.cpp
    dicpp/lib/src/scopes/singleton.cpp
    dicpp/lib/src/demangle.cpp
    dicpp/lib/src/registry.cpp
    dicpp/lib/src/empty.cpp
    dicpp/lib/src/type_provider.cpp
)

add_library(
    gscore STATIC
    gs/Script.cpp
    gs/Parser.cpp
    gs/Function.cpp
    gs/stmt/CallMethod.cpp
    gs/VariableTable.cpp
    gs/ScriptFactory.cpp
    gs/ParserFactory.cpp
    gs/FunctionFactory.cpp
    gs/Compiler.cpp
    gs/CompilerFactory.cpp
    gs/StatementHandler.cpp
    gs/StatementFactory.cpp
    gs/stmt/Return.cpp
    gs/expr/Object.cpp
    gs/expr/MethodCall.cpp
    gs/ExpressionFactory.cpp
)

add_executable(
    gamescriptut
    gs/test/unit/main.cpp
    gs/test/GoogleTestController.cpp
    gs/test/unit/Script.cpp
    gs/test/unit/Parser.cpp
    gs/test/unit/Function.cpp
    gs/test/unit/stmt/CallMethod.cpp
    gs/test/unit/ObjectMapper.cpp
    gs/test/unit/VariableTable.cpp
    gs/test/unit/Compiler.cpp
    gs/test/unit/StatementHandler.cpp
    gs/test/unit/stmt/Return.cpp
    gs/test/unit/expr/Object.cpp
    gs/test/unit/expr/MethodCall.cpp
)

add_executable(
    gamescriptat
    gs/test/acceptance/main.cpp
    gs/test/GoogleTestController.cpp
    gs/test/acceptance/calls.cpp
    gs/test/acceptance/returns.cpp
    gs/test/acceptance/localVars.cpp
)

target_link_libraries(gamescriptut gscore gmock dicpp pthread boost_regex)
target_link_libraries(gamescriptat gscore gmock dicpp pthread boost_regex)
