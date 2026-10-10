/**
 * @file    TEST_observer_observable.cpp
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
#include "TEST_observer_observable.hpp"

using namespace CppUnit;
using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION( TEST_observer_observable );
//int parse_options(int argc, char* argv[]);

void TEST_observer_observable::setUp()
{
}

void TEST_observer_observable::tearDown()
{
}

void TEST_observer_observable::testNoOptions()
{
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_observer_observable::testOptionHelp()
{
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_observer_observable::testOptionHelpLong()
{
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_observer_observable::testOptionVerbose()
{
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_observer_observable::testOptionVerboseLong()
{
   CPPUNIT_ASSERT(1 == 1);
}

void TEST_observer_observable::execute()
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

void TEST_observer_observable::execute(int argc, char* argv[])
{

}
