/**
 * @file    scope.hpp
 * @version 0.0.1
 * @date    Thu, 22 Oct 2026 15:44:25 +0000
 */
#ifndef _scope_HPP_
#define _scope_HPP_
#include <iostream>
#include <vector>
#include <string>
#include "symbols.hpp"

using std::string;
using std::vector;

/**
  * @brief class scope
  */
class scope
{
public:
	/**
	* @brief : default ctor
	*/
	scope() = default;

	/**
	* @brief : copy ctor
	*/
	scope( const scope& src ) = default;
	
		/**
	* @brief : destructor
	*/
	~scope() = default;
		
protected:
	string name_;
	vector<scope> scopes_;
	symbols* symbols_;
};

#endif
