/**
 * @file     logger.hpp
 * @date:    Thu Oct 31 01:46:28 PM CDT 2024
 * @version: 0.0.1
 */
#ifndef _logger_HPP
#define _logger_HPP

#include <limits>
#include <string>
#include <fstream>
#include <ostream>
#include "singleton.hpp"

using std::string;
using std::fstream;
using std::ostream;

/**
 * @class logger : singleton<logger>
 */
class logger : public singleton_base<logger>
{
    friend class singleton_base<logger>; // access private constructor  
private:
    logger() = default;
public:
    logger(const logger&) = delete;
    logger& operator=(const logger&) = delete;

    /**
     * @name logger dtor
     * @brief logger dtor
     */
    ~logger();

public:
    /**
     * @name open
     * @param  const string& log_file
     */
    void open(const string& log_file);

    /**
     * @name log
     * @param const string& msg
     */
    void log(const string& msg);

    /**
     * @name operator<<
     * @param string& msg
     */
    logger& operator<<(const string& msg);

    /**
     * @name operator<<
     * @param int n
     */
    logger& operator<<(int n);

    /**
     * @name operator<<
     * @param long n
     */
    logger& operator<<(long n);

    /**
     * @name operator<<
     * @param float n
     */
    logger& operator<<(float n);

    /**
     * @name operator<<
     * @param double n
     */
    logger& operator<<(double n);

    // /**
    //  * @name fstream& oparator<<
    //  */
    // fstream& operator<<(fstream& os, const logger& log);

    
private:
    std::ofstream* strm;
    const static string BEGIN;
    const static string END;
};

#endif