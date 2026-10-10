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
     * @brief: agregate test functions
     */ 
    void execute();

    /**
     * @brief: agregate test functions
     */ 
    void execute(int argc, char* argv[]);

protected:
    void testNoOptions();
    void testOptionHelp();
    void testOptionHelpLong();
    void testOptionVerbose();
    void testOptionVerboseLong();

private:
    int m_argc;
    char* m_argv[10];

};

#endif
