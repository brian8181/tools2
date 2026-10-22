/**
 * @file    file_scope.hpp
 * @version 0.0.1
 * @date    Thu, 22 Oct 2026 15:44:38 +0000
 */
#ifndef _file_scope_HPP_
#define _file_scope_HPP_
#include <iostream>
#include "scope.hpp"

/**
  * @brief class file_scope
  */
class file_scope : public scope
{
public:
	/**
	* @brief : default ctor
	*/
	file_scope() = default;

		/**
	* @brief : copy ctor
	*/
	file_scope( const file_scope& src ) = default;
	
		/**
	* @brief : destructor
	*/
	~file_scope() = default;
	
private:
};

#endif
