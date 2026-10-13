/**
 * @file     logger.cpp
 * @date:    Thu Oct 31 01:46:28 PM CDT 2024
 * @version: 0.0.1
 */
#include <iostream>
#include <limits>
#include <string>
#include <fstream>
#include "logger.hpp"

using std::string;
using std::ofstream;
using std::endl;

const string logger::BEGIN = "************ Begin Log : ************** --> ";
const string logger::END   = "************ End Log   : ************** -->";

/**
 * @name logger dtor
 * @brief logger dtor
 */
logger::~logger()
{
    *strm << END << __TIME__  << " " << __DATE__ << std::endl;
    strm->close();
    delete strm;    
}

/**
 * @name open
 * @param  const string& log_file
 */
void logger::open(const string& log_file)
{
    strm = new ofstream(log_file, std::ofstream::out | std::ofstream::app);
    *strm << BEGIN << __TIME__ << " " << __DATE__ << std::endl;
}

/**
 * @name log
 * @param const string& msg
*/
void logger::log(const string& msg)
{
    *strm << msg << " -> " << __TIME__ << " " << __DATE__ << std::endl;
}

/**
 * @name operator<<
 * @param string& msg
 */
logger& logger::operator<<(const string& msg)
{
    *strm << msg;
    return *this;
}

/**
 * @name operator<<
 * @param int n
 */
logger& logger::operator<<(int n)
{
    *strm << n;
    return *this;
}

// /**
//  * @name fstream& oparator<<
//  */
// fstream& logger::operator<<(fstream& os, const logger& log)
// {
//     os << "testing";
//     return os;
// }

