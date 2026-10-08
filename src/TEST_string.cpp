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
using std::cout;
using std::endl;


CPPUNIT_TEST_SUITE_REGISTRATION( TEST_string );

void TEST_string::setUp()
{
}

void TEST_string::tearDown()
{
}

/**
 * @name: execute
 * @return: void
 * @brief: agregate test functions
 */ 
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

 /**
 * @name: execute
 * @return: void
 * @param: int argc
 * @param: char* argv[]
 * @brief: agregate test functions
 */ 
void TEST_string::execute(int argc, char* argv[])
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

void TEST_string::test_digits10()
{
    int expected = 4;
    int actual = digits10(1234);
    std::cout << "\ndigits=" << actual << std::endl;
    CPPUNIT_ASSERT(expected == actual);

    expected = 01;
    actual = digits10(1);
    std::cout << "\ndigits=" << actual << std::endl;
    CPPUNIT_ASSERT(actual == expected);
}
void TEST_string::test_replace_all()
{
    string str = "abcxabcxabc";
    cout << "str=" << str << endl; 
    string sub_str = "x";
    string rpl = "BOO";
    replace_all(str, sub_str, rpl);
    cout << "str=" << str << endl; 
    CPPUNIT_ASSERT(str == "abcBOOabcBOOabc");
}

void TEST_string::test_reverse()
{
   char s[] = "1234567890";
   cout << endl << "s=" << s << endl; 
   reverse(s, 10);
   string excepted = string(s);
   cout << "s=" << s << endl; 
   CPPUNIT_ASSERT(excepted == "0987654321");
}

void TEST_string::test_int_to_str()
{
    int n = 123456;
    string r;
    int_to_str(n, r);
    CPPUNIT_ASSERT(r == "123456");
}

void TEST_string::test_str_to_int()
{
    string s = "123456";
    int n = 0;
    str_to_int(s, n);
    CPPUNIT_ASSERT(n == 123456);
}

void TEST_string::test_to_lower()
{
    string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    cout << endl << "s=" << s << endl; 
    string r;
    to_lower(s, r);
    cout << "r=" << r << endl; 
    CPPUNIT_ASSERT(r == "abcdefghijklmnopqrstuvwxyz0123456789");

    s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    cout << endl << "s=" << s << endl; 
    r = to_lower(s);
    cout << "r=" << r << endl; 
    CPPUNIT_ASSERT(r == "abcdefghijklmnopqrstuvwxyz0123456789");

    char ps[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    cout << endl << "ps=" << ps << endl; 
    char* pr = 0;
    //const char pr = to_lower(ps);
    //cout << "pr=" << pr << endl; 
    CPPUNIT_ASSERT(r == "abcdefghijklmnopqrstuvwxyz0123456789");
}

void TEST_string::test_to_upper()
{
    string s = "abcdefghijklmnopqrstuvwxyz0123456789";
    cout << endl << "s=" << s << endl; 
    string r;
    to_upper(s, r);
    cout << "r=" << r << endl; 
    CPPUNIT_ASSERT(r == "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");

    s = "abcdefghijklmnopqrstuvwxyz0123456789";
    cout << endl << "s=" << s << endl; 
    r = to_upper(s);
    cout << "r=" << r << endl; 
    CPPUNIT_ASSERT(r == "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");

    char ps[] = "abcdefghijklmnopqrstuvwxyz0123456789";
    cout << endl << "ps=" << ps << endl; 
    char* pr = 0;
    //const char pr = to_lower(ps);
    //cout << "pr=" << pr << endl; 
    CPPUNIT_ASSERT(r == "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
}

void TEST_string::test_ltrim()
{
    string s = " abc";
    string expected = "abc";
    string actual = ltrim(s);
    CPPUNIT_ASSERT(actual == expected);
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
    int expected = 1234;
    string s = "1234";
    int actual = atoi(s.c_str());
    cout << endl << "actual=" << actual << endl;
    CPPUNIT_ASSERT(actual == expected);

    expected = 1;
    s = "1";
    actual = atoi(s.c_str());
    cout << endl << "actual=" << actual << endl;
    CPPUNIT_ASSERT(actual == expected);

    expected = 0;
    s = "0";
    actual = atoi(s.c_str());
    cout << endl << "actual=" << actual << endl;
    CPPUNIT_ASSERT(actual == expected);

    expected = 1000;
    s = "1000";
    actual = atoi(s.c_str());
    cout << endl << "actual=" << actual << endl;
    CPPUNIT_ASSERT(actual == expected);
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


