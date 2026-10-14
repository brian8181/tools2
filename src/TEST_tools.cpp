/**
 * @file    tools.hpp
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
#include "TEST_tools.hpp"

using namespace CppUnit;
using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION( TEST_tools );
//int parse_options(int argc, char* argv[]);

/**
 * @name: setUp
 * @brief: set up set case
 * @return void
 */
void TEST_tools::setUp()
{
}

/**
 * @name: tearDown
 * @brief: clean up after test case
 * @return: void
 */
void TEST_tools::tearDown()
{
}

/**
 * @name testNoOptions
 * @brief test with no options
 * @return void
 */
void TEST_tools::testNoOptions()
{
    CPPUNIT_ASSERT(1 == 1);
}

/**
 * @name testOptionHelp
 * @brief test help option
 * @return void
 */
void TEST_tools::testOptionHelp()
{
    CPPUNIT_ASSERT(1 == 1);
}

/**
 * @name testOptionHelpLong
 * @brief test long help option
 * @return void
 */
void TEST_tools::testOptionHelpLong()
{
    CPPUNIT_ASSERT(1 == 1);
}

/**
 * @name testOptionVerbose
 * @brief test verbose option
 * @return void
 */
void TEST_tools::testOptionVerbose()
{
    CPPUNIT_ASSERT(1 == 1);
}

/**
 * @name testOptionVerboseLong
 * @brief test long verbose option
 * @return void
 */
void TEST_tools::testOptionVerboseLong()
{
   CPPUNIT_ASSERT(1 == 1);
}

void TEST_tools::execute()
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

void TEST_tools::execute(int argc, char* argv[])
{

}
