#include "Options.h"
#include <string>
#include <iostream>

Options::Options(std::string name, double cost): _name(name),_cost(cost)
{
    //Constructors-Create the object class
}
Options::~Options()
{
    //Destructor
}

double Options::cost()
{
    return _cost;
}
std::string Options::to_string() const
{
    return _name + "  $"+ std::to_string(_cost);
}
std::ostream& operator<<(std::ostream& ost,  Options& add_option)
{
    return ost<<add_option.to_string() ; 
}
void Options::save(std::ostream& ost) const
{
    ost<<_name<<std::endl;
    ost<<_cost<<std::endl;
}

Options::Options(std::istream& ist)
{
    getline(ist,_name);
    std::string text ;
    getline(ist,text);
    double val = std::stod(text);
    _cost = val;

}
Options* Options::ptr() const
{
    return new Options{*this};
}