/** @file    string.hpp
  * @version 0.0.1
  * @date    Fri Oct  2 05:23:39 AM CDT 2026
  * @brief   todo
  */
#ifndef _string_HPP
#define _string_HPP

#include <iostream>
#include <vector>
#include <map>

using std::string;
using std::vector;
using std::string;
using std::vector;
using std::map;

/**
 * @name getconfig
 * @info0: git name -> value pairs/config
 * @param path, path to config file
 */
std::map<string, string>& get_config(const string& path, /** out */ map<string, string>& config);

/**
 * @name replace_all
 * @brief replace 'sub_str' with 'replace_str' in 's'
 * @param std::string& s
 * @param const std::string& sub_str 
 * @return void
 */
void replace_all( std::string& s, const std::string& sub_str, const std::string& replace_str );

/**
 * @name reverse
 * @brief reverse char str[]
 * @param char str[]
 * @param int length
 * @return void
 */
void reverse( char str[ ], int length );

/**
 * @name long_to_str
 * @parm: return number of base 10 digits
 * @param n, number to eval
 * @return void
 */
void long_to_str( long num, std::string& str );

/**
 * @name str_to_long
 * @parm: return number of base 10 digits
 * @param n, number to eval
 * @return void
 */
void str_to_long( long num, std::string& str );

/**
 * @name int_to_str
 * @parm: return number of base 10 digits
 * @param n, number to eval
 * @return void
 */
void int_to_str( int num, std::string& str );

/**
 * @name str_to_int
 * @parm: return number of base 10 digits
 * @param n, number to eval
 * @return void
 */
void str_to_int( const std::string& str, int& num );

/**
 * @name to_lower
 * @param const string& s
 * @param string& r
 * @return string&
 */
string& to_lower(const string& s, /** out */ string& r);

/**
 * @name to_lower
 * @brief in place to_lower
 * @param string& s
 * @return string&
 */
string& to_lower(string& s);

/**
 * @name to_lower
 * @brief in place to_lower
 * @param const char* s
 * @return const char*
 */
const char* to_lower(const char* s);

/**
 * @name to_upper
 * @param const string& s
 * @param string& r
 * @return string&
 */
string& to_upper(const string& s, /** out */ string& r);

/**
 * @name to_upper
 * @brief in place to_upper
 * @param const string& s
 * @return string&
 */
string& to_upper(string& s);

/**
 * @name to_upper
 * @brief in place to_upper
 * @param const char* s
 * @return const char*
 */
const char* to_upper(const char* s);

/**
 * @name ltrim
 * @brief in place to_ltrim
 * @param std::string& s
 * @return string&
 */
string& ltrim(string& s);

/**
 * @name rtrim
 * @brief in place to_rtrim
 * @param std::string& s
 * @return string&
 */
string& rtrim(string& s);

/**
 * @name trim
 * @brief in place to_trim
 * @param std::string& s
 * @return string&
 */
string& trim(string& s);

/**
 * @name digits10
 * @brief return number of base 10 digits
 * @param n, number to eval
 * @return int
 */
int digits10(int n);

/** 
 * @name atoi
 * @brief ascii to int
 * @param s, string to convert
 * @return int result
 */
int atoi(const char* s) noexcept;

/** 
 * @name name: itoa
 * @param int to ascii
 * @param n, number to eval
 * @param s, out parma
 * @return void
 */
void itoa(int& n, char* s);

/**
 * 
 */
typedef string line_t;
typedef vector<line_t> lines_t;
typedef string field_t;
typedef vector<field_t> record_t;
typedef vector<record_t> table_t;

/**
 * 
 */
string rebase(const unsigned int n, const unsigned int base);

/**
 * 
 */
template<class InputIt, class T, class FunT>
void split(InputIt first, InputIt last, const T& delim, FunT output);

/**
 * 
 */
std::vector<std::string> split(const std::string& s, char c);

#endif