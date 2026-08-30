
# @name     tools2
# @file:    CMakeLists.txt
# @date:    Wed Aug 19 07:31:13 AM CDT 2026
# @version: 0.0.1

cmake_minimum_required(VERSION 3.28.3)
project(tools2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find CppUnit
#find_package(PkgConfig REQUIRED)
#pkg_check_modules(CPPUNIT REQUIRED cppunit)

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
    src/singleton_base.hpp
    src/singleton_base_std11.hpp    
)

# Create test executable
#add_executable(TestTools ${TEST_SOURCES})

# Link libraries
# target_link_libraries(TestTools 
#     ${PROJECT_NAME}_lib
#     ${CPPUNIT_LIBRARIES}
# )