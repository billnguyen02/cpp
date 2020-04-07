#include "Options.h"
#include <string>
#include <iostream>

Options::Options(std::string name, double cost): _name{name},_cost{cost}
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
std::string Options::to_string()
{
    return _name + "$ "+ std::to_string(_cost);
}
std::ostream& operator<<(std::ostream& ost, const Options& add_option)
{
    return ost<<add_option._name <<" "<< add_option._cost<<"$" ; 
}