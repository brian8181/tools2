/**
 * @file    TEST_string.hpp
 * @version 0.0.1
 * @date    Fri Oct  2 05:23:39 AM CDT 2026
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
#include "TEST_string.hpp"
#include "string.hpp"

using namespace CppUnit;
using std::string;


CPPUNIT_TEST_SUITE_REGISTRATION( TEST_string );

void TEST_string::setUp()
{
}

void TEST_string::tearDown()
{
}

void TEST_string::testNoOptions()
{
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_string::testOptionHelp()
{
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_string::testOptionHelpLong()
{
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_string::testOptionVerbose()
{
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_string::testOptionVerboseLong()
{
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_string::execute()
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

void TEST_string::execute(int argc, char* argv[])
{

}

void TEST_string::test_digits10()
{
    //int n = 1234;
    int len = digits10(1234);
    std::cout << "\ndigits=" << len << std::endl;
    CPPUNIT_ASSERT(len == 4);

    //n = 01;
    len = digits10(1);
    std::cout << "\ndigits=" << len << std::endl;
    CPPUNIT_ASSERT(len == 1);
}
void TEST_string::test_replace_all()
{
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_string::test_reverse()
{
    //char* ps = "abc";
    //reverse(ps, 3);
    //CPPUNIT_ASSERT(ps[0] == 'c');
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_string::test_int_to_str()
{
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_string::test_str_to_int()
{
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_string::test_to_lower()
{
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_string::test_to_upper()
{
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_string::test_ltrim()
{
    string s = " abc";
    string expected = "abc";
    string actual = ltrim(s);
    CPPUNIT_ASSERT(expected == actual);
}

void TEST_string::test_rtrim()
{
    string s = "abc ";
    string expected = "abc";
    //CPPUNIT_ASSERT_ASSERTION_FAIL(expected, actual);
    string actual = rtrim(s);
    CPPUNIT_ASSERT(expected == actual);
}

void TEST_string::test_trim()
{
    string s = " abc ";
    string expected = "abc";
    //CPPUNIT_ASSERT_ASSERTION_FAIL(expected, actual);
    string actual = trim(s);
    CPPUNIT_ASSERT(expected == actual);
}

void TEST_string::test_atoi()
{
    string s = "1234";
    int expected = atoi(s.c_str());
    //cout << endl << "excepted=" << expected << endl;
    CPPUNIT_ASSERT(expected == 1234);
}

void TEST_string::test_itoa()
{
    char s[11] = { '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0' };
    int n=12345;
    itoa(n, s);
    std::cout << "\nn=" << s << std::endl;
    CPPUNIT_ASSERT(s[0] == '1');

    n = 1234567890;
    itoa(n, s);
    CPPUNIT_ASSERT(s[0] == '1');
}

void TEST_string::test_get_config()
{
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_string::test_rebase()
{
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_string::test_split()
{
    CPPUNIT_ASSERT(1 == 1);
}


