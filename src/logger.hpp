// File Name:  logger.hpp
// Build Date: Thu Oct 31 01:46:28 PM CDT 2024
// Version:    0.0.1

#ifndef _logger_HPP
#define _logger_HPP

#include <string>
#include <fstream>
#include <ostream>
#include "singleton.hpp"

using std::string;
using std::fstream;
using std::ostream;

class logger : public singleton_base<logger>
{
    friend class singleton_base<logger>; // access private constructor  
private:
    logger() = default;
public:
    logger(const logger&) = delete;
    logger& operator=(const logger&) = delete;
    ~logger();

public:
    void open(const string& log_file);
    void log(const string& msg);
    logger& operator<<(const string& msg);
    logger& operator<<(int n);
    logger& operator<<(double n);
    logger& operator<<(long n);

private:
    std::ofstream* strm;
    const static string BEGIN;
    const static string END;
};

#endif