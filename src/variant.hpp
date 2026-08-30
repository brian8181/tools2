/**
 * @file    variant.hpp
 * @version 0.0.1
 * @date    Sat, 25 Jul 2026 14:00:10 +0000
 */
#ifndef _variant_HPP_
#define _variant_HPP_
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

/**
  * @brief class variant
  */
class variant
{
	// signed unsigned
	// short, int, long, float, double, char, string
	enum etype
	{
		VAR_I4,
		VAR_CSTR
	};

	/**
	* @brief : ctor
	*/
	variant( const long& val ) : m_type(VAR_I4), m_long_val(val)
	{
	}

	/**
	* @brief : ctor
	*/
	variant( char*& val ) : m_type(VAR_CSTR), m_str_val(val)
	{
	}

	/**
	* @brief : copy ctor
	*/
	variant( const variant& src )
	{
	}
	
	/**
	* @brief : destructor
	*/
	~variant()
	{
		clear();
	}

	void clear()
	{
	}
	
	operator long()
	{
		return 0;
	}

	operator char*()
	{
		int len = std::strlen(m_str_val); 
		return new char[len+1];
	}

	void operator=(const variant& src)
	{
		clear();
		//etype type = src.m_type;
		switch(m_type)
		{
			case etype::VAR_I4:
				break;
			case etype::VAR_CSTR:
				break;
		}
	}
	
private:
	etype m_type;
	union
	{
		char* m_str_val;
		long m_long_val;
	};
	
};

#endif
