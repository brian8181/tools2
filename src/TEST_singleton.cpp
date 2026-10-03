/**
 * @file    TEST_singleton.hpp
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
#include "TEST_singleton.hpp"
#include "logger.hpp"

using namespace CppUnit;
using namespace std;


CPPUNIT_TEST_SUITE_REGISTRATION( TEST_singleton );

/**
 * @name: setUp
 * @return: void
 * @brief: set up set case
 */
void TEST_singleton::setUp()
{
}

/**
 * @name: tearDown
 * @return: void
 * @brief: clean up after test case
 */
void TEST_singleton::tearDown()
{
}

/**
 * @name: execute
 * @return: void
 * @brief: agregate test functions
 */ 
void TEST_singleton::execute()
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
 * @param: int argc
 * @parma: char* argv[]
 * @return: void
 * @brief: agregate test functions
 */ 
void TEST_singleton::execute(int argc, char* argv[])
{

}

void TEST_singleton::testNoOptions()
{
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_singleton::testOptionHelp()
{
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_singleton::testOptionHelpLong()
{
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_singleton::testOptionVerbose()
{
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_singleton::test_singleton_instance()
{
    logger& log = logger::instance();
    log.open("test.log");
    log.log("This is a test message.");
    log.log("This is a test message with source.");
    log.log("This is a test message with line number.");
    log.log("This is a test message with source and line number.");
    // *log << "This is a test message using operator<<." << std::endl;
    // *log << 123 << std::endl;
    // *log << 45.67 << std::endl;
    // *log << 890L << std::endl;
}   
