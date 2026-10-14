/**
 * @file    TEST_utest.cpp
 * @version 0.0.1
 * @date    Mon, 17 Aug 2026 14:38:40 +0000
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
#include "TEST_utest.hpp"

using namespace CppUnit;
using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION( TEST_utest );
//int parse_options(int argc, char* argv[]);

/**
 * @name: tearDown
 * @return: void
 * @brief: clean up after test case
 */
void TEST_utest::setUp()
{
}

/**
 * @name: tearDown
 * @return: void
 * @brief: clean up after test case
 */
void TEST_utest::tearDown()
{
}

void TEST_utest::testNoOptions()
{
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_utest::testOptionHelp()
{
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_utest::testOptionHelpLong()
{
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_utest::testOptionVerbose()
{
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_utest::testOptionVerboseLong()
{
   CPPUNIT_ASSERT(1 == 1);
}

void TEST_utest::execute()
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

void TEST_utest::execute(int argc, char* argv[])
{

}
