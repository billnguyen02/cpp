#ifdef __LOG_H
#include<iostream>
#include<string>
#define LOG(msg)
    std::cerr<<__FILE__<<"("<<__LINE__<< "): " <<msg<<std::endl
#else
#define LOG(msg)
#endif