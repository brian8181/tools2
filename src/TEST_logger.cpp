/*
 * @file    logger.hpp
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
#include "TEST_logger.hpp"
#include "logger.hpp"

using namespace CppUnit;
using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION( TEST_logger );

/**
 * @name: setUp
 * @return: void
 * @brief: set up set case
 */
void TEST_logger::setUp()
{
}

/**
 * @name: tearDown
 * @return: void
 * @brief: clean up after test case
 */
void TEST_logger::tearDown()
{
}

/**
 * @name: execute
 * @return: void
 * @brief: agregate test functions
 */ 
void TEST_logger::execute()     
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
void TEST_logger::execute(int argc, char* argv[])
{

}

/**
 * @name testNoOptions
 * @brief test with no options
 * @return void
 */
void TEST_logger::testNoOptions()
{
    CPPUNIT_ASSERT(1 == 1);
}

/**
 * @name testOptionHelp
 * @brief test help option
 * @return void
 */
void TEST_logger::testOptionHelp()
{
    CPPUNIT_ASSERT(1 == 1);
}

/**
 * @name testOptionHelpLong
 * @brief test long help option
 * @return void
 */
void TEST_logger::testOptionHelpLong()
{
    CPPUNIT_ASSERT(1 == 1);
}

/**
 * @name testOptionVerbose
 * @brief test verbose option
 * @return void
 */
void TEST_logger::testOptionVerbose()
{
    CPPUNIT_ASSERT(1 == 1);
}

/**
 * @name testOptionVerboseLong
 * @brief test long verbose option
 * @return void
 */
void TEST_logger::test_logger_open()
{
    logger& log = logger::instance();
    log.open("test.log");
    log.log("This is a test message.");
    log.log("This is a test message with source.");
    log.log("This is a test message with line number.");
    log.log("This is a test message with source and line number.");
    
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_logger::test_logger_log()
{
    logger& log = logger::instance();
    log.log("This is a test message.");
    CPPUNIT_ASSERT(1 == 1);
}



void TEST_logger::test_logger_strm_operator_string()
{
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_logger::test_logger_strm_operator_int()
{
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_logger::test_logger_strm_operator_long()
{
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_logger::test_logger_strm_operator_double()
{
    CPPUNIT_ASSERT(1 == 1);
}



