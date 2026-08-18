
# @name     tools2
# @file:    CMakeLists.txt
# @date:    Mon, 17 Aug 2026 14:38:40 +0000
# @version: 0.0.1

cmake_minimum_required(VERSION 3.28.3)
project(tools2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#set(BUILD_SHARED_LIBS YES)

if(CMAKE_SYSTEM_NAME STREQUAL "CYGWIN")
    message(STATUS "Building under Cygwin, defining CYGWIN macro")
    add_definitions(-DCYGWIN)
endif()


add_library(tools2_a STATIC
    src/utility.cpp 
    src/fileio.cpp 
    src/utest.cpp 
    src/singleton.cpp 
    src/variant.cpp 
    src/logger.cpp
    src/loop.cpp
    src/symtab.c
)