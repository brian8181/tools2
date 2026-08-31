/**
 * @file    TEST_singleton.hpp
 * @version 0.0.1
 * @date    Mon, 17 Aug 2026 14:38:40 +0000
 */
#ifndef _TEST_singleton_H
#define _TEST_singleton_H

#include <cppunit/Test.h>

class TEST_singleton : public CppUnit::TestFixture
{
private:
    CPPUNIT_TEST_SUITE(TEST_singleton);
    CPPUNIT_TEST(testNoOptions);
    CPPUNIT_TEST(testOptionHelp);
    CPPUNIT_TEST(testOptionHelpLong);
    CPPUNIT_TEST(testOptionVerbose);
    //CPPUNIT_TEST(test_logger_open);
    CPPUNIT_TEST(test_singleton_instance);
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
    void test_singleton_instance();
private:
    int m_argc;
    char* m_argv[10];
    //logger* m_logger;

};

#endif
