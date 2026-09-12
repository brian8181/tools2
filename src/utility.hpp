#ifndef _utility_HPP
#define _utility_HPP

#include <iostream>
#include <vector>
#include <map>

using std::string;
using std::vector;


using std::string;
using std::vector;
using std::map;

std::map<string, string>& get_config(const string& path, /* out */ map<string, string>& config);
void replace_all( std::string& s, const std::string& sub_str, const std::string& replace_str );
void reverse( char str[ ], int length );

/*
 * @name: long_to_str
 * @parm: return number of base 10 digits
 * @param: n, number to eval
 * @return: void
 */
void long_to_str( long num, std::string& str );

/*
 * @name: str_to_long
 * @parm: return number of base 10 digits
 * @param: n, number to eval
 * @return: void
 */
void str_to_long( long num, std::string& str );

/*
 * @name: int_to_str
 * @parm: return number of base 10 digits
 * @param: n, number to eval
 * @return: void
 */
void int_to_str( int num, std::string& str );

/*
 * @name: str_to_int
 * @parm: return number of base 10 digits
 * @param: n, number to eval
 * @return: void
 */
void str_to_int( const std::string& str, int& num );

string& to_lower(const string& s, /* out */ string& r);
string& to_lower(string& s); // in place
string& to_upper(const string& s, /* out */ string& r);
string& to_upper(string& s); // in place
string& ltrim(string& s);
string& rtrim(string& s);
string& trim(string& s);

template <typename ...Args>
void print(const Args& ...args);

/*
 * @name: digits10
 * @info: return number of base 10 digits
 * @param: n, number to eval
 * @return: int
 */
int digits10(int n);

/* name: atoi
 * info: ascii to int
 * s, string to convert
 * return: int result
 */
int atoi(const char* s);

/* @name name: itoa
 * @param: int to ascii
 * @param: n, number to eval
 * @param: s, out parma
 * @return: void
 */
void itoa(int& n, char* s);

template<class InputIt, class T, class FunT>
void split(InputIt first, InputIt last, const T& delim, FunT output);

typedef string line_t;
typedef vector<line_t> lines_t;
typedef string field_t;
typedef vector<field_t> record_t;
typedef vector<record_t> table_t;

std::vector<std::string> split(const std::string& s, char c);


//vector<long>& psieve(const int& end, vector<long>& ret);

//template <typename T> bool equal(const T& a, const T& b);

//void redim(int from, int to);
string rebase(const unsigned int n, const unsigned int base);

#endif