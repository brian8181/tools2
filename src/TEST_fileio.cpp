/**
 * @file    fileio.hpp
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
#include "TEST_fileio.hpp"
#include "fileio.hpp"

using namespace CppUnit;
using namespace std;


CPPUNIT_TEST_SUITE_REGISTRATION( TEST_fileio );

/**
 * @name: setUp
 * @return: void
 * @brief: set up set case
 */
void TEST_fileio::setUp()
{
}

/**
 * @name: tearDown
 * @return: void
 * @brief: clean up after test case
 */
void TEST_fileio::tearDown()
{
}

 /**
 * @name: execute
 * @return: void
 * @brief: agregate test functions
 */ 
void TEST_fileio::execute()
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
void TEST_fileio::execute(int argc, char* argv[])
{

}

void TEST_fileio::testNoOptions()
{
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_fileio::testOptionHelp()
{
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_fileio::testOptionHelpLong()
{
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_fileio::testOptionVerbose()
{
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_fileio::testOptionVerboseLong()
{
   CPPUNIT_ASSERT(1 == 1);
}

void TEST_fileio::test_file_size() 
{
    string file = "../test/test.config";
    long sz = file_size("../test/test.config");
    cout << file << " = " << sz << " BYTES" << endl;
    CPPUNIT_ASSERT(sz != 0);
}

void TEST_fileio::test_file_exist() 
{
    string file = "../test/test.config";
    bool exist = file_exist("../test/test.config");
    CPPUNIT_ASSERT(exist == true);
}

void TEST_fileio::test_get_ofstream() 
{ 
    string file = "../test/test.config";
    ofstream* strm = 0;
    get_ofstream(file, strm);
    CPPUNIT_ASSERT(strm != 0);
}

void TEST_fileio::test_get_ifstream() 
{ 
    string file = "../test/test.config";
    ifstream* strm = 0;
    get_ifstream(file, strm);
    CPPUNIT_ASSERT(strm != 0);
}

void TEST_fileio::test_getc() 
{ 
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_fileio::test_read_char() 
{ 
    string file = "../test/test_read_char.txt";
    ifstream* strm = 0;
    get_ifstream(file, strm);
    
    char c;
    //read_char(*strm, c);
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_fileio::test_write_char() 
{ 
    string file = "../test/test_write_char.txt";
    ofstream* strm = 0;
    get_ofstream(file, strm);

    char c;
    //write_char(*strm, c);
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_fileio::test_read_buf() 
{
    string file = "../test/test_read_buf.txt";
    unsigned char buffer[1024];
    read_buf(file, buffer, 1024);
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_fileio::test_write_buf() 
{ 
    string file = "../test/test_read_buf.txt";
    unsigned char buffer[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    //write_buf(file, &buffer[0], 26);
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_fileio::test_read_str() 
{ 
    string file = "../test/test_read_str.txt";
    string str;
    read_str(file, str);
    CPPUNIT_ASSERT(str.length() > 0);
}
void TEST_fileio::test_write_str() 
{ 
    string file = "../test/test_write_str.txt";
    string out = "Hello World!";
    int ret = write_str(file, out);
    CPPUNIT_ASSERT(ret != 0);
}
void TEST_fileio::test_read_sstream() 
{ 
    string file = "../test/test.config";
    stringstream ostrm;
    read_sstream(file, ostrm);
    // todo
    CPPUNIT_ASSERT(ostrm.str().size() != 0);
}
void TEST_fileio::test_write_sstream() 
{ 
    CPPUNIT_ASSERT(1 == 1);
}
void TEST_fileio::test_read_line() 
{ 
    CPPUNIT_ASSERT(1 == 1);
}
void TEST_fileio::test_write_line() 
{ 
    string file = "../test/test_write.txt";
    stringstream ss;
    ss << "Test1" << endl;
    write_sstream(file, ss);
    // todo
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_fileio::test_read_lines() 
{ 
    CPPUNIT_ASSERT(1 == 1);
}
void TEST_fileio::test_write_lines() 
{ 
    CPPUNIT_ASSERT(1 == 1);
}

