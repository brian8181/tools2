// File Name:  lower_test.cpp
// Build Date: Sat Sep  7 12:20:36 AM CDT 2024
// Version:    0.0.1

#include <iostream>
#include <string>
#include "utility.hpp"

using std::string;

int main(int argc, char* argv[])
{
    string s = "TESTING";
    string r;
    to_lower(s, r);
    std::cout << s << " : " << r << std::endl;
    string& out = to_lower(s, r);
    std::cout << s << " : " << out << std::endl;

    string& ret = to_lower(s);
    std::cout << s << " : " << ret << std::endl;
}
