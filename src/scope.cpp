/**
 * @file    scope.hpp
 * @version 0.0.1
 * @date    Thu, 22 Oct 2026 15:44:25 +0000
 */
#include "scope.hpp"

/**
 * @brief : add a scope to the current scope
 * @param s : scope to add
 * @return void	
 */
void scope::add_scope(const scope& s)
{
    scopes_.push_back(s);
}	
