#include <iostream>
#include <cstring>
#include <string>
#include <unistd.h>         /* for STDIN_FILENO */
#include <sys/select.h>     /* for pselect   */
#include <string>
#include <getopt.h>
#include <vector>
#include "utility.hpp"

using std::cout;
using std::endl;
using std::vector;

int parse_options(int argc, char* argv[])
{
    int n = 1234;
    int len = digits10(1234);
    std::cout << "digits=" << len << std::endl;

	n = 1234;
	char s[11] = { '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0' };
	itoa(n, s);
	std::cout << "n=" << s << std::endl;
	n=12345;
	itoa(n, s);
	std::cout << "n=" << s << std::endl;

	n=1234567890;
	itoa(n, s);
	std::cout << "n=" << s << std::endl;

	// for(int i = 1; i < n; ++i)
	// {
	// 	itoa(i, s);
    // 	std::cout << "n=" << s << std::endl;
	// }


	// run prime sieve
	std::vector<long> ps;
	len = 10000;
	ps.reserve(len*10);
	psieve(len, ps);

	long size = ps.size();
	for(int i = 0; i < size; ++i)
	{
		cout << "idx=" << i << "; val=" << ps[i] << endl;
	}

	return 0;
}

int stdin_ready (int filedes)
{
	fd_set set;
	// declare/initialize zero timeout 
	struct timespec timeout = { .tv_sec = 0 };
	// initialize the file descriptor set
	FD_ZERO(&set);
	FD_SET(filedes, &set);
	// check stdin_ready is ready on filedes 
	return pselect(filedes + 1, &set, NULL, NULL, &timeout, NULL);
}

int main(int argc, char* argv[])
{
	try
	{
		if(stdin_ready(STDIN_FILENO))
		{
			std::string buffer;
			std::cin >> buffer;
			// add piped buffer to end of argv
			char* argvtmp[sizeof(char*) * argc+1];
			memcpy(argvtmp, argv, sizeof(char*) * argc);
			argvtmp[argc] = &buffer[0];
			argv = argvtmp;
			++argc;
		}
		return parse_options(argc, argv);
	}
	catch(std::logic_error& ex)
	{
	 	std::cout << ex.what() << std::endl;
	}
}


