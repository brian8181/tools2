/**
 * @file    variant.hpp
 * @version 0.0.1
 * @date    Mon, 17 Aug 2026 14:38:40 +0000
 */
#ifndef _TEST_variant_H
#define _TEST_variant_H

#include <cppunit/Test.h>

class TEST_variant : public CppUnit::TestFixture
{
private:
    CPPUNIT_TEST_SUITE(TEST_variant);
    CPPUNIT_TEST(testNoOptions);
    CPPUNIT_TEST(testOptionHelp);
    CPPUNIT_TEST(testOptionHelpLong);
    CPPUNIT_TEST(testOptionVerbose);
    CPPUNIT_TEST(testOptionVerboseLong);
    CPPUNIT_TEST(test_ctor1);
    CPPUNIT_TEST(test_ctor2);
    CPPUNIT_TEST(test_ctor3);
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

    void test_ctor1();
    void test_ctor2();
    void test_ctor3();

private:
    int m_argc;
    char* m_argv[10];

};

#endif
