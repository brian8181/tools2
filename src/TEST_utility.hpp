/**
 * @file    utility.hpp
 * @version 0.0.1
 * @date    Mon, 17 Aug 2026 14:38:40 +0000
 */
#ifndef _TEST_utility_H
#define _TEST_utility_H

#include <cppunit/Test.h>

class TEST_utility : public CppUnit::TestFixture
{
private:
    CPPUNIT_TEST_SUITE(TEST_utility);
    CPPUNIT_TEST(testNoOptions);
    CPPUNIT_TEST(testOptionHelp);
    CPPUNIT_TEST(testOptionHelpLong);
    CPPUNIT_TEST(testOptionVerbose);
    CPPUNIT_TEST(testOptionVerboseLong);
    CPPUNIT_TEST(test_to_lower);
    CPPUNIT_TEST(test_to_upper);
    CPPUNIT_TEST(test_rtrim);
    CPPUNIT_TEST(test_ltrim);
    CPPUNIT_TEST(test_trim);
    CPPUNIT_TEST(test_itoa);
    CPPUNIT_TEST(test_atoi);
    CPPUNIT_TEST(test_get_config);
    CPPUNIT_TEST(test_rebase);
    CPPUNIT_TEST(test_split);
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
    void test_to_lower();
    void test_to_upper();
    void test_rtrim();
    void test_ltrim();
    void test_trim();
    void test_itoa();
    void test_atoi();
    void test_get_config();
    void test_rebase();
    void test_split();

private:
    int m_argc;
    char* m_argv[10];

};

#endif
