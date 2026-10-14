/**
 * @file    TEST_observer_observable.hpp
 * @version 0.0.1
 * @date    Mon, 17 Aug 2026 14:38:40 +0000
 */
#ifndef _TEST_observer_observable_H
#define _TEST_observer_observable_H

#include <cppunit/Test.h>

class TEST_observer_observable : public CppUnit::TestFixture
{
private:
    CPPUNIT_TEST_SUITE(TEST_observer_observable);
    CPPUNIT_TEST(testNoOptions);
    CPPUNIT_TEST(testOptionHelp);
    CPPUNIT_TEST(testOptionHelpLong);
    CPPUNIT_TEST(testOptionVerbose);
    CPPUNIT_TEST(testOptionVerboseLong);
    CPPUNIT_TEST_SUITE_END();

public:
    /**
     * @name: setUp
     * @brief: set up set case
     */
    void setUp();

    /**
     * @name: tearDown
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

private:
    int m_argc;
    char* m_argv[10];

};

#endif
