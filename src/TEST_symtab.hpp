/**
 * @file    symtab.hpp
 * @version 0.0.1
 * @date    Mon, 17 Aug 2026 14:38:40 +0000
 */
#ifndef _TEST_symtab_H
#define _TEST_symtab_H

#include <cppunit/Test.h>

class TEST_symtab : public CppUnit::TestFixture
{
private:
    CPPUNIT_TEST_SUITE(TEST_symtab);
    CPPUNIT_TEST(testNoOptions);
    CPPUNIT_TEST(testOptionHelp);
    CPPUNIT_TEST(testOptionHelpLong);
    CPPUNIT_TEST(testOptionVerbose);
    CPPUNIT_TEST(testOptionVerboseLong);
    CPPUNIT_TEST(test_get_stable);
    CPPUNIT_TEST(test_freenode);
    CPPUNIT_TEST(test_init_symbol);
    CPPUNIT_TEST(test_init_sub_table);
    CPPUNIT_TEST(test_add_symbol);
    CPPUNIT_TEST(test_insert_symbol);
    CPPUNIT_TEST(test_remove_symbol);
    CPPUNIT_TEST(test_clear_symbols);
    CPPUNIT_TEST(test_find_symbol_by_addr);
    CPPUNIT_TEST(test_find_symbol_by_id);
    CPPUNIT_TEST(test_find_symbol);
    CPPUNIT_TEST(test_find_node);
    CPPUNIT_TEST(test_find_tail);
    CPPUNIT_TEST(test_size);
    CPPUNIT_TEST_SUITE_END();

public:
    /**
     * @name: setUp
     * @return: void
     * @brief: set up set case
     */
    void setUp();

    /**
     * @name: tearDown
     * @return: void
     * @brief: clean up after test case
     */
    void tearDown();

    /**
     * @name: execute
     * @return: void
     * @brief: agregate test functions
     */ 
    void execute();

    /**
     * @name: execute
     * @return: void
     * @param: int argc
     * @param: char* argv[]
     * @brief: agregate test functions
     */ 
    void execute(int argc, char* argv[]);

protected:
   /**
     * @name testNoOptions
     * @brief test with no options
     * @return void
     */
    void testNoOptions();

    /**
     * @name testOptionHelp
     * @brief test help option
     * @return void
     */
    void testOptionHelp();

    /**
     * @name testOptionHelpLong
     * @brief test long help option
     * @return void
     */
    void testOptionHelpLong();
    
    /**
     * @name testOptionVerbose
     * @brief test verbose option
     * @return void
     */
    void testOptionVerbose();

    /**
     * @name testOptionVerboseLong
     * @brief test long verbose option
     * @return void
     */
    void testOptionVerboseLong();
    
    /**
     * @name test_get_stable
     * @brief test get stable function
     * @return void
     */
    void test_get_stable();

    /**
     * @name test_freenode
     * @brief test free node function
     * @return void
     */
    void test_freenode();

    /**
     * @name test_init_symbol
     * @brief test initialize symbol function
     * @return void
     */
    void test_init_symbol();

    /**
     * @name test_init_sub_table
     * @brief test initialize sub table function
     * @return void
     */
    void test_init_sub_table();

    /**
     * @name test_add_symbol
     * @brief test add symbol function
     * @return void
     */ 
    void test_add_symbol();

    /**
     * @name test_insert_symbol
     * @brief test insert symbol function
     * @return void
     */
    void test_insert_symbol();

    /**
     * @name test_remove_symbol
     * @brief test remove symbol function
     * @return void
     */
    void test_remove_symbol();

    /**
     * @name test_clear_symbols
     * @brief test clear symbols function
     * @return void
     */  
    void test_clear_symbols();

    /**
     * @name test_find_symbol_by_addr
     * @brief test find symbol by address function
     * @return void
     */
    void test_find_symbol_by_addr();

    /**
     * @name test_find_symbol_by_id
     * @brief test find symbol by id function
     * @return void
     */
    void test_find_symbol_by_id();

    /**
     * @name test_find_symbol
     * @brief test find symbol function
     * @return void
     */
    void test_find_symbol();


    /**
     * @name test_find_node
     * @brief test find node function
     * @return void
     */
    void test_find_node();

    /**
     * @name test_find_tail
     * @brief test find tail function
     * @return void
     */
    void test_find_tail();

    /**
     * @name test_size
     * @brief test size function
     * @return void
     */
    void test_size();

private:
    int m_argc;
    char* m_argv[10];

};

#endif
