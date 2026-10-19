/**
 * @file    tools2.hpp
 * @version version 0.0.1
 * @date    Wed Aug 19 01:47:09 PM CDT 2026
 */
#include <iostream>
#include <cstring>
#include <unistd.h> /* for STDIN_FILENO */
#if defined(_WIN32)
// Windows-specific code (e.g., MSYS2 UCRT64)
#include <winsock2.h>
#elif defined(__linux__)
// Linux-specific code (e.g., Fedora, Ubuntu)
#include <sys/select.h>
#elif defined(__unix__)
// Other Unix-like systems (e.g., BSD, macOS)
#include <sys/select.h>
#endif
#include <cstdlib>
#include <getopt.h>
#include "tools.hpp"
#include "fileio.hpp"
#include "string.hpp"
#include "bash_color.hpp"

using std::string;
using std::cout;
using std::cerr;
using std::endl;

const string VERSION_STRING = "0.0.1";
const int DEFAULT_ARGC = 0;
const unsigned short VERBOSE          = 0x01;
const unsigned short DEFAULTS         = 0x00;
const unsigned short FIELDS           = 0x02;
unsigned short options = DEFAULTS;
char DELIMITER = ',';

static struct option long_options[] =
{
        {"verbose", no_argument, 0, 'v'},
        {"help", no_argument, 0, 'h'},
        {"version", no_argument, 0, 'r'},
};

unsigned short OPTION_FLAGS = DEFAULTS;

void print_version()
{
	cout << VERSION_STRING << endl;
}

void print_help()
{
	cout	<< endl
			<< FMT_BOLD      << FMT_FG_GREEN << "Usage: " << FMT_RESET << endl
			<< FMT_BOLD      << " $APP_NAME " << FMT_RESET << " "
			<< FMT_FG_BLUE   << "[-hvr][...]"             << FMT_RESET << " "
         												  <<  endl << endl;
}

union color
{
    /** Red component */
    unsigned char r;
    /** Green component */
    unsigned char g;
    /** Blue component */
    unsigned char b;
    /** Alpha component */
    unsigned char a;
    /** 32 bit color value */
    unsigned int value;
};

int parse_options(int argc, char* argv[])
{
	int opt = 0;
	int option_index = 0;
	optind = 0;
	while ((opt = getopt_long(argc, argv, "hv ", long_options, &option_index)) != -1)
	{
		switch (opt)
		{
			case 'h':
				print_help();
				return 0;
			case 'v':
				print_version();
				return 0;
		}
	}

	if (argc < DEFAULT_ARGC) // not correct number of args
	{
		cerr << "Expected argument after options, -h for help" << endl;
		return -1;
	}

	string path = argv[0];   // get exe file path
	cout << argv[0] << endl;

	string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    cout << endl << "s=" << s << endl; 
    string r;
    to_lower(s, r);
    cout << "r=" << r << endl; 
    union color c;
    c.r = 0xFF;
    c.g = 0x00;
    c.b = 0x00; 
    c.a = 0xFF;
    cout << "color value: 0x" << std::hex << std::setw(8) << std::setfill('0') << c.value << std::dec << endl; 
    return 0;
}

#ifndef _WIN32
/**
 * @brief  stdin_ready function
 * @param filedes
 * @param int filedes : the file handle
 * @return ready or error code
 */
int stdin_ready(int filedes)
{
    fd_set set;
    // declare/initialize zero timeout
#ifndef CYGWIN
    struct timespec timeout = {.tv_sec = 0};
#else
    timeval timeout = {.tv_sec = 0};
#endif
    // initialize the file descriptor set
    FD_ZERO(&set);
    FD_SET(filedes, &set);
    // check stdin_ready is ready on filedes
#ifndef CYGWIN
    return pselect(filedes + 1, &set, NULL, NULL, &timeout, NULL);
#else
    return select(filedes + 1, &set, nullptr, nullptr, &timeout);
#endif
}
#endif

/**
 * @brief main function
 * @param argc : param count in argv
 * @param argv : command line parameters
 * @return 0 success : or error
 */
int main(int argc, char *argv[])
{
    try
    {
#ifndef _WIN32
        char *argv_cpy[sizeof(char *) * argc + 1];
        if (stdin_ready(STDIN_FILENO))
        {
            std::string buffer;
            std::cin >> buffer;
            memcpy(argv_cpy, argv, sizeof(char *) * argc);
            argv_cpy[argc] = &buffer[0];
            ++argc;
            return parse_options(argc, argv_cpy);
        }
#endif
        return parse_options(argc, argv);
    }
    catch (std::runtime_error &ex)
    {
        std::cout << ex.what() << std::endl;
        std::exit(-1);
    }
    catch (std::logic_error &ex)
    {
        std::cout << ex.what() << std::endl;
        std::exit(-1);
    }
}
