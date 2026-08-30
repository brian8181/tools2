# Find CppUnit
find_package(PkgConfig REQUIRED)
pkg_check_modules(CPPUNIT REQUIRED cppunit)

# Test sources
set(TEST_SOURCES
    TEST_tools2.cpp
    TEST_utility.cpp
    TEST_fileio.cpp
    TEST_utest.cpp
    TEST_singleton.cpp
    TEST_variant.cpp
    TEST_logger.cpp
    TEST_loop.cpp
    TEST_symtab.cpp
    TEST_singleton_base.cpp

# Create test executable
add_executable(ast_utest ${TEST_SOURCES})

# Link libraries
target_link_libraries(TEST_tools 
    ${PROJECT_NAME}_lib
    ${CPPUNIT_LIBRARIES}
)

# Include directories
target_include_directories(ast_utest PRIVATE ${CPPUNIT_INCLUDE_DIRS})

# Compiler flags
target_compile_options(ast_utest PRIVATE ${CPPUNIT_CFLAGS_OTHER})

# Add test to CTest
add_test(NAME UnitTests COMMAND ast_utest)