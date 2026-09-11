/**
 * @file    scopedptr.hpp
 * @version 0.0.1
 * @date    Thu, 10 Sep 2026 09:42:55 +0000
 */
#ifndef _scopedptr_HPP_
#define _scopedptr_HPP_
#include <iostream>

/**
  * @brief class scopedptr
  */
 template <typename T>
class scopedptr
{
public:
	/**
	* @brief : default ctor
	*/
	scopedptr() { m_ptr = new T(); }

	
	/**
	* @brief : destructor
	*/
	~scopedptr() { delete m_ptr; }
	
private:
	T* m_ptr = nullptr;
};

#endif
