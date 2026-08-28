#include <iostream>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>

using namespace CppUnit;
using namespace std;

using std::cout;
using std::endl;

int main() 
{

    #ifdef __CYGWIN__
        std::cout << "Running on Cygwin." << std::endl;
    #elif _WIN32
        std::cout << "Running on Windows (but not Cygwin)." << std::endl;
    #else
        std::cout << "Running on a non-Windows, non-Cygwin system." << std::endl;
    #endif
    
    // Create the event manager and test controller
    CppUnit::TestResult controller;

    // Add a listener that collects test results
    CppUnit::TestResultCollector result;
    controller.addListener( &result );

    // Add a listener that prints dots as tests run
    CppUnit::BriefTestProgressListener progress;
    controller.addListener( &progress );

    // Add the top suite to the test runner
    CppUnit::TestRunner runner;
    runner.addTest( CppUnit::TestFactoryRegistry::getRegistry().makeTest() );
    runner.run( controller );

    // Print test results
    CppUnit::CompilerOutputter outputter( &result, std::cerr );
    outputter.write();

    return result.wasSuccessful() ? 0 : 1;
}

// int main(int argc, char* argv[])
// {
//     // informs test-listener about testresults
//     CPPUNIT_NS::TestResult testresult;

//     // register listener for collecting the test-results
//     CPPUNIT_NS::TestResultCollector collectedresults;
//     testresult.addListener (&collectedresults);

//     // register listener for per-test progress output
//     CPPUNIT_NS::BriefTestProgressListener progress;
//     testresult.addListener (&progress);

//     // insert test-suite at test-runner by registry
//     CPPUNIT_NS::TestRunner testrunner;
//     testrunner.addTest (CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest ());
//     testrunner.run(testresult);

//     // output resint* pn = new int;ults in compiler-format
//     CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
//     compileroutputter.write ();

//     // Output XML for Jenkins CPPunit plugin
//     ofstream xmlFileOut("cppTEST_tools2Results.xml");
//     XmlOutputter xmlOut(&collectedresults, xmlFileOut);
//     xmlOut.write();

//     // return 0 if tests were successful
//     return collectedresults.wasSuccessful() ? 0 : 1;
// }