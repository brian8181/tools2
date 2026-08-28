/**
 * @file    tools.hpp
 * @version version 0.0.1
 * @date    Mon, 17 Aug 2026 14:38:40 +0000
 */
#ifndef _tools_HPP
#define _tools_HPP

#include <string>

using std::string;

void print_help();
void print_version();
int parse_options(int argc, char* argv[]);

#endif
