#ifndef ___DESKTOP__H   
#define ___DESKTOP__H

#include "Options.h"
#include <string>
#include <iostream>
#include <vector>


class Desktop
{
    public:
        void add_option(Options& add_options);
        friend std::ostream& operator<<(std::ostream& ost, const Desktop& desktop);
        double price();
        void save(std::ostream& ost);
        Desktop(std::istream& ist);
        Desktop();
        int size();
        void fix_option(int option);
    private:
        std::vector< Options*> _options;
};
#endif