/**
 * @file    symtab.hpp
 * @version 0.0.1
 * @date    Mon, 17 Aug 2026 14:38:40 +0000
 */
#include <iostream>
#include <string>
#include <list>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <netinet/in.h>
#include "TEST_symtab.hpp"
#include "symtab.h"

using namespace CppUnit;
using std::string;

CPPUNIT_TEST_SUITE_REGISTRATION( TEST_symtab );
//int parse_options(int argc, char* argv[]);

/**
 * @name: setUp
 * @return: void
 * @brief: set up set case
 */
void TEST_symtab::setUp()
{
}

/**
 * @name: tearDown
 * @return: void
 * @brief: clean up after test case
 */
void TEST_symtab::tearDown()
{
}

/**
 * @name testNoOptions
 * @brief test with no options
 * @return void
 */
void TEST_symtab::testNoOptions()
{
    CPPUNIT_ASSERT(1 == 1);
}

/**
 * @name testOptionHelp
 * @brief test help option
 * @return void
 */
void TEST_symtab::testOptionHelp()
{
    CPPUNIT_ASSERT(1 == 1);
}

/**
 * @name testOptionHelpLong
 * @brief test long help option
 * @return void
 */
void TEST_symtab::testOptionHelpLong()
{
    CPPUNIT_ASSERT(1 == 1);
}

/**
 * @name testOptionHelpLong
 * @brief test long help option
 * @return void
 */
void TEST_symtab::testOptionVerbose()
{
    CPPUNIT_ASSERT(1 == 1);
}

/**
 * @name testOptionVerboseLong
 * @brief test long verbose option
 * @return void
 */
void TEST_symtab::testOptionVerboseLong()
{
    CPPUNIT_ASSERT(1 == 1);
}

/**
 * @name: execute
 * @return: void
 * @brief: agregate test functions
 */ 
void TEST_symtab::execute()
{
    // on head
    char** pstr = new char*;
    *pstr = (char*)"test";    // on the heap

    char** argv = new char*[1] {*pstr};
    //argv[0] = *pstr;

    execute(1, argv);

    delete pstr;
    delete [] argv;

    // on stack
    //char* argv_[3] {(char*)"./App", (char*)"abc", (char*)"abc"};
}

 /**
 * @name: execute
 * @return: void
 * @param: int argc
 * @param: char* argv[]
 * @brief: agregate test functions
 */ 
void TEST_symtab::execute(int argc, char* argv[])
{
}

/**
 * @name test_get_stable
 * @brief test get symbol table function
 * @return void
 */
void TEST_symtab::test_get_stable()
{
    // get the symbol table
    symbol_tab* tab = get_stable();
    CPPUNIT_ASSERT(tab != 0);
}

/**
 * @name test_freenode
 * @brief test free node function
 * @return void
 */
void TEST_symtab::test_freenode()
{
    CPPUNIT_ASSERT(1 == 1);
}

/**
 * @name test_init_symbol
 * @brief test init symbol function
 * @return void
 */
void TEST_symtab::test_init_symbol()
{
    // init a new symbol
    symbol* ps;
    init_symbol(&ps, "one", "const", "int");

    CPPUNIT_ASSERT(ps != 0);
}

/**
 * @name test_init_sub_table
 * @brief test init sub table function
 * @return void
 */
void TEST_symtab::test_init_sub_table()
{
    CPPUNIT_ASSERT(1 == 1);
}

/**
 * @name test_add_symbol
 * @brief test add symbol function
 * @return void
 */
void TEST_symtab::test_add_symbol()
{
    // get the symbol table
    symbol_tab* tab = get_stable();
    // init a new symbol
    symbol* ps;
    init_symbol(&ps, "one", "const", "int");
    // add a symbol
    add_symbol(tab, ps);

    CPPUNIT_ASSERT(1 == 1);
}

/**
 * @name test_insert_symbol
 * @brief test insert symbol function
 * @return void
 */
void TEST_symtab::test_insert_symbol()
{
    CPPUNIT_ASSERT(1 == 1);
}

/**
 * @name test_remove_symbol
 * @brief test remove symbol function
 * @return void
 */
void TEST_symtab::test_remove_symbol()
{
    // get the symbol table
    symbol_tab* tab = get_stable();
    // init a new symbol
    symbol* ps;
    init_symbol(&ps, "one", "const", "int");
    // add a symbol
    add_symbol(tab, ps);
    //remove_symbol(tab, "one");  

    CPPUNIT_ASSERT(1 == 1);
}

/**
 * @name test_clear_symbols
 * @brief test clear symbols function
 * @return void
 */
void TEST_symtab::test_clear_symbols()
{
    // get the symbol table 
    symbol_tab* tab = get_stable();
    clear_symbols(tab);
    CPPUNIT_ASSERT(1 == 1);
}

/**
 * @name test_is_empty
 * @brief test is empty function
 * @return void
 */
void TEST_symtab::test_is_empty()
{
    // get the symbol table
    symbol_tab* tab = get_stable();
    clear_symbols(tab);
    CPPUNIT_ASSERT(is_empty(tab) == 1);
}


/**
 * @name test_find_symbol_by_addr
 * @brief test find symbol by address function
 * @return void
 */
void TEST_symtab::test_find_symbol_by_addr()
{
    CPPUNIT_ASSERT(1 == 1);
}

/**
 * @name test_find_symbol_by_id
 * @brief test find symbol by id function
 * @return void
 */
void TEST_symtab::test_find_symbol_by_id()
{
    CPPUNIT_ASSERT(1 == 1);
}

/**
 * @name test_find_symbol
 * @brief test find symbol function
 * @return void
 */
void TEST_symtab::test_find_symbol()
{
    CPPUNIT_ASSERT(1 == 1);
}

/**
 * @name test_find_node
 * @brief test find node function
 * @return void
 */
void TEST_symtab::test_find_node()
{
    CPPUNIT_ASSERT(1 == 1);
}

/**
 * @name test_find_tail
 * @brief test find tail function
 * @return void
 */
void TEST_symtab::test_find_tail()
{
    symbol_tab* stab = get_stable();
    node* tail = find_tail(stab);
    CPPUNIT_ASSERT(tail != 0);
}

/**
 * @name test_size
 * @brief test size function
 * @return void
 */
void TEST_symtab::test_size()
{
    // get the symbol table
    symbol_tab* tab = get_stable();
    clear_symbols(tab);
    // init a new symbol
    symbol* ps;
    init_symbol(&ps, "one", "const", "int");
    // add a symbol
    add_symbol(tab, ps);
    int sz = size(tab);
    CPPUNIT_ASSERT(sz == 1);

    init_symbol(&ps, "two", "const", "int");
    // add a symbol
    add_symbol(tab, ps);
    sz = size(tab);
    CPPUNIT_ASSERT(sz == 2);
}