/**
 * @file    logger.hpp
 * @version 0.0.1
 * @date    Mon, 17 Aug 2026 14:38:40 +0000
 */
#ifndef _TEST_logger_H
#define _TEST_logger_H

#include <cppunit/Test.h>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "logger.hpp"

class TEST_logger : public CppUnit::TestFixture
{
private:
    CPPUNIT_TEST_SUITE(TEST_logger);
    CPPUNIT_TEST(testNoOptions);
    CPPUNIT_TEST(testOptionHelp);
    CPPUNIT_TEST(testOptionHelpLong);
    CPPUNIT_TEST(testOptionVerbose);
    CPPUNIT_TEST(test_logger_open);
    CPPUNIT_TEST(test_logger_log);
    CPPUNIT_TEST(test_logger_strm_operator_string);
    CPPUNIT_TEST(test_logger_strm_operator_int);
    CPPUNIT_TEST(test_logger_strm_operator_long);
    CPPUNIT_TEST(test_logger_strm_operator_double);
    CPPUNIT_TEST_SUITE_END();

public:
    /**
     * @name: setUp
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
     * @name execute
     * @brief: agregate test functions
     * @return: void
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

    void test_logger_open();
    void test_logger_log();
    void test_logger_strm_operator_string();
    void test_logger_strm_operator_int();
    void test_logger_strm_operator_long();
    void test_logger_strm_operator_double();
private:
    int m_argc;
    char* m_argv[10];
    logger* m_logger;
};

#endif
