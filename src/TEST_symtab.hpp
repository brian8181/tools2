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
    CPPUNIT_TEST(test_init_symbol);
    CPPUNIT_TEST(test_add_symbol);
    CPPUNIT_TEST(test_remove_symbol);
    CPPUNIT_TEST(test_find_symbol_by_addr);
    CPPUNIT_TEST(test_find_symbol_by_id);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

    // agregate test functions
    void execute();
    void execute(int argc, char* argv[]);

protected:
    void testNoOptions();
    void testOptionHelp();
    void testOptionHelpLong();
    void testOptionVerbose();
    void testOptionVerboseLong();
    void test_get_stable();
    void test_init_symbol();
    void test_add_symbol();
    void test_remove_symbol();
    void test_find_symbol_by_addr();
    void test_find_symbol_by_id();
    
private:
    int m_argc;
    char* m_argv[10];

};

#endif
