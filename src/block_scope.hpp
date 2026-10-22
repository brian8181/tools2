/**
 * @file    block_scope.hpp
 * @version 0.0.1
 * @date    Thu, 22 Oct 2026 15:45:23 +0000
 */
#ifndef _block_scope_HPP_
#define _block_scope_HPP_
#include <iostream>
#include "scope.hpp"

/**
  * @brief class block_scope
  */
class block_scope : public scope
{
public:
	/**
	* @brief : default ctor
	*/
	block_scope() = default;

		/**
	* @brief : copy ctor
	*/
	block_scope( const block_scope& src ) = default;
	
		/**
	* @brief : destructor
	*/
	~block_scope() = default;

private:


};

#endif
