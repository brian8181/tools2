/**
 * @file    symbols.hpp
 * @version 0.0.1
 * @date    Thu, 22 Oct 2026 15:43:20 +0000
 */
#ifndef _symbols_HPP_
#define _symbols_HPP_
#include <iostream>
#include <map>

using std::map;

/**
  * @brief class symbols
  */
class symbols
{
public:
	/**
	* @brief : default ctor
	*/
	symbols() = default;

		/**
	* @brief : copy ctor
	*/
	symbols( const symbols& src ) = default;
	
		/**
	* @brief : destructor
	*/
	~symbols() = default;
	
protected:
	map<std::string, std::string> table_;

};

#endif
