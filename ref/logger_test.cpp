#include <iostream>
#include "logger.hpp"
#include <sstream>
#include <fstream>


int main(int argc, char* argv[])
{
    //logger* p_logger  = logger::instance();

    string filename = argv[0];
    filename.append(".log");

    logger::instance().open(filename);
    std::stringstream ss;
    ss << "LINE: " << __LINE__ << " OF FILE: " << __FILE__ << " " << __TIME__ << " " << __DATE__ << std::endl;
    logger::instance().log(ss.str());
    logger::instance().log("testing ...");

    // // use stream operator
    // *p_logger << __LINE__ << __FILE__ << " stream op testing ...";

    // filename.append("2");
    // fstream strm;
    // strm.open (filename, std::fstream::in | std::fstream::out | std::fstream::app);
    // strm << "testing " << p_logger << std::endl;
    // //strm << "LINE: " << __LINE__ << " OF FILE: " << __FILE__ << " " << __TIME__ << " " << __DATE__ << std::endl;
    
    return 0;
}