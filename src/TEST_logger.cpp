/**
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
#include <string.h>
#include <iostream>
#include <string>
#include "logger.hpp"

using namespace CppUnit;
using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION( TEST_logger );

void TEST_logger::setUp()
{
}

void TEST_logger::tearDown()
{
}

void TEST_logger::testNoOptions()
{
    //CPPUNIT_ASSERT(parse_options(m_argc, m_argv) == 0);
}

void TEST_logger::testOptionHelp()
{
    //CPPUNIT_ASSERT(parse_options(m_argc, m_argv) == 0);
}

void TEST_logger::testOptionHelpLong()
{
    //CPPUNIT_ASSERT(parse_options(m_argc, m_argv) == 0);
}

void TEST_logger::testOptionVerbose()
{
    //CPPUNIT_ASSERT(parse_options(m_argc, m_argv) == 0);
}

void TEST_logger::test_logger_open()
{
    logger& log = logger::getInstance();
    log.open("test.log");
    log.log("This is a test message.");
    log.log("This is a test message with source.", "TEST_logger.cpp");
    log.log("This is a test message with line number.", 42);
    log.log("This is a test message with source and line number.", "TEST_logger.cpp", 42);
    // //*log << "This is a test message using operator<<." << std::endl;
    // *log << 123 << std::endl;
    // *log << 45.67 << std::endl;
    // *log << 890L << std::endl;
   //CPPUNIT_ASSERT(parse_options(m_argc, m_argv) == 0);
}

void TEST_logger::test_logger_log()
{
    logger& log = logger::getInstance();
    log.log("This is a test message.");
    //CPPUNIT_ASSERT(parse_options(m_argc, m_argv) == 0);
}

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

void TEST_logger::execute(int argc, char* argv[])
{

}


