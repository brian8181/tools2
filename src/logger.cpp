// File Name:  logger.cpp
// Build Date: Thu Oct 31 01:46:28 PM CDT 2024
// Version:    0.0.1

#include <iostream>
#include <string>
#include <fstream>
#include "logger.hpp"

using std::string;
using std::ofstream;
using std::endl;

const static string BEGIN = "************ Begin Log : __TIME__ **************";
const static string END   = "************ End Log : __TIME__ ****************";

logger::~logger()
{
    log("END __TIME__");
    strm->close();
    delete strm;    
}

void logger::open(const string& log_file)
{
    strm = new ofstream(log_file, std::ofstream::out);
    log("BEGIN __TIME__");
}

void logger::log(const string& msg)
{
    *strm << msg << " -> LINE: " << __LINE__ << " OF FILE: " << __FILE__ << " " << __TIME__ << " " << __DATE__ << std::endl;
}

logger& logger::operator<<(const string& msg)
{
    *strm << msg;
    return *this;
}

logger& logger::operator<<(int n)
{
    *strm << n;
    return *this;
}

// fstream& operator<<(fstream& os, const logger& log)
// {
//     os << "testing";
//     return os;
// }

