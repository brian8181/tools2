/**
 * @file    fileio.hpp
 * @version 0.0.1
 * @date    Mon, 17 Aug 2026 14:38:40 +0000
 */
#ifndef _TEST_fileio_H
#define _TEST_fileio_H

#include <cppunit/Test.h>

class TEST_fileio : public CppUnit::TestFixture
{
private:
    CPPUNIT_TEST_SUITE(TEST_fileio);
    CPPUNIT_TEST(testNoOptions);
    CPPUNIT_TEST(testOptionHelp);
    CPPUNIT_TEST(testOptionHelpLong);
    CPPUNIT_TEST(testOptionVerbose);
    CPPUNIT_TEST(testOptionVerboseLong);
    CPPUNIT_TEST(test_file_size);
    CPPUNIT_TEST(test_file_exist);
    CPPUNIT_TEST(test_get_ofstream);
    CPPUNIT_TEST(test_get_ifstream);
    CPPUNIT_TEST(test_getc);
    CPPUNIT_TEST(test_read_char);
    CPPUNIT_TEST(test_write_char);
    CPPUNIT_TEST(test_read_buf);
    CPPUNIT_TEST(test_write_buf);
    CPPUNIT_TEST(test_read_str);
    CPPUNIT_TEST(test_write_str);
    CPPUNIT_TEST(test_read_sstream);
    CPPUNIT_TEST(test_write_sstream);
    CPPUNIT_TEST(test_read_buf);
    CPPUNIT_TEST(test_write_buf);
    CPPUNIT_TEST(test_read_line);
    CPPUNIT_TEST(test_write_line);
    CPPUNIT_TEST(test_read_lines);
    CPPUNIT_TEST(test_write_lines);
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
    void test_file_size();
    void test_file_exist();
    void test_get_ofstream();
    void test_get_ifstream();
    void test_getc();
    void test_read_char();
    void test_write_char();
    void test_read_buf();
    void test_write_buf();
    void test_read_str();
    void test_write_str();
    void test_read_sstream();
    void test_write_sstream();
    void test_read_line();
    void test_write_line();
    void test_read_lines();
    void test_write_lines();

private:
    int m_argc;
    char* m_argv[10];

};

#endif
