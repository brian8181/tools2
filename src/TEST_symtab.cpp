/**
 * @file    symtab.hpp
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
#include "TEST_symtab.hpp"
#include <string.h>

using namespace CppUnit;
using namespace std;


CPPUNIT_TEST_SUITE_REGISTRATION( TEST_symtab );

void TEST_symtab::setUp()
{
}

void TEST_symtab::tearDown()
{
}

void TEST_symtab::testNoOptions()
{
    //CPPUNIT_ASSERT(parse_options(m_argc, m_argv) == 0);
}

void TEST_symtab::testOptionHelp()
{
    //CPPUNIT_ASSERT(parse_options(m_argc, m_argv) == 0);
}

void TEST_symtab::testOptionHelpLong()
{
    //CPPUNIT_ASSERT(parse_options(m_argc, m_argv) == 0);
}

void TEST_symtab::testOptionVerbose()
{
    //CPPUNIT_ASSERT(parse_options(m_argc, m_argv) == 0);
}

void TEST_symtab::testOptionVerboseLong()
{
   CPPUNIT_ASSERT(1 == 1);
}

void TEST_symtab::test_get_stable()
{
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_symtab::test_init_symbol()
{
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_symtab::test_add_symbol()
{
    CPPUNIT_ASSERT(1 == 1);
}


void TEST_symtab::test_remove_symbol()
{
    CPPUNIT_ASSERT(1 == 1);
}  

void TEST_symtab::test_find_symbol_by_addr()
{
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_symtab::test_find_symbol_by_id()
{
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_symtab::execute()
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

void TEST_symtab::execute(int argc, char* argv[])
{

}


