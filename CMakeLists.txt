project(gamescript)

cmake_minimum_required(VERSION 2.8)

include_directories("." "gmock-1.5.0/fused-src" "dicpp/include")

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

add_executable(
    gamescriptut
    gs/test/unit/main.cpp
    gs/test/GoogleTestController.cpp
)

add_executable(
    gamescriptat
    gs/test/acceptance/main.cpp
    gs/test/GoogleTestController.cpp
)

target_link_libraries(gamescriptut gmock dicpp pthread)
target_link_libraries(gamescriptat gmock dicpp pthread)