/**
 * @file    scope.hpp
 * @version 0.0.1
 * @date    Thu, 22 Oct 2026 15:44:25 +0000
 */
#ifndef _scope_HPP_
#define _scope_HPP_
#include <iostream>
#include "symbols.hpp"

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
		

private:
	symbols* symbols_;
};

#endif
