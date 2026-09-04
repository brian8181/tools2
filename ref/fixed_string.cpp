#include "fixed_string.hpp"
#include <cstring>

//  fixed_string::fixed_string(int lenght)
//  {
//     buffer = new char[length];
//  }

// fixed_string::fixed_string(int lenght, char* buf)
// {
//     buffer = new char[length];
//     buf = buffer;
// }

// fixed_string::fixed_string(const fixed_string& s)
// {
//     buffer = new char[length];
//     std::strcpy(buffer, s.buffer);
// }

// fixed_string::~fixed_string()
// {
//     delete [] buffer;
// }

// bool fixed_string::operator==(const fixed_string& s)
// {
//     for(int i =0; i < length ;++i)
//     {
//         if(buffer[i] != s.buffer[i])
//             return false;
//     }
// }

// int fixed_string::get_lenght()
// {
//     return length;
// }

// fixed_string* fixed_string::copy()
// {
//     fixed_string* cpy = new fixed_string(*this);
//     return cpy;
// }

// fixed_string* fixed_string::copy(int beg, int len)
// {
//     fixed_string* cpy = new fixed_string(len);
//     std::strncpy(cpy->buffer, buffer, len);
//     return cpy;
// }

// void fixed_string::free()
// {
//     delete [] buffer;
// }

// void fixed_string::copy_from(char& buf)
// {
//     free();
//     int len = strlen(&buf);
//     strcpy(&buf, buffer);
// }

// void fixed_string::copy_from(const char* buf, int beg, int len)
// {
//     free();
//     strncpy(&buffer[beg], buf, len);
// }

// void fixed_string::copy_from(const char* buf, int src_beg, int dst_beg)
// {
//     free();
//     strcpy(&buffer[dst_beg], &buf[src_beg]);
// }

// void fixed_string::copy_from(const char* buf, int src_beg, int dst_beg, int len)
// {
//     free();
//     strncpy(&buffer[dst_beg], &buf[src_beg], len);
// }
