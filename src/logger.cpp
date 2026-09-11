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

const string logger::BEGIN = "************ Begin Log : ************** --> ";
const string logger::END   = "************ End Log   : ************** -->";

logger::~logger()
{
    *strm << END << __TIME__  << " " << __DATE__ << std::endl;
    strm->close();
    delete strm;    
}

void logger::open(const string& log_file)
{
    strm = new ofstream(log_file, std::ofstream::out | std::ofstream::app);
    *strm << BEGIN << __TIME__ << " " << __DATE__ << std::endl;
}

void logger::log(const string& msg)
{
    *strm << msg << " -> " << __TIME__ << " " << __DATE__ << std::endl;
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

