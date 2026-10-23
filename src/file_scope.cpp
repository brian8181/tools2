/**
 * @file    file_scope.hpp
 * @version 0.0.1
 * @date    Thu, 22 Oct 2026 15:44:38 +0000
 */
#include <string>
#include "file_scope.hpp"
#include "symbols.hpp"

using std::string;

/**
 * @brief : constructor with file path
 * @param file_path : path to the file
 */
file_scope::file_scope(const string& file_path) : name_(file_path), symbols_(new symbols()), file_path_(file_path)
{
}
