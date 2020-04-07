#ifndef ___OPTIONS__H   
#define ___OPTIONS__H

#include <string>
#include <iostream>

class Options
{
    protected:
        std::string _name;
        double _cost;
    public:
        Options(std::string name, double cost);
        ~Options();
        double cost();
        std::string to_string() const;
        friend std::ostream& operator<<(std::ostream& ost, const Options& add_option);
        void save(std::ostream& ost);
        Options(std::istream& ist);
};


#endif