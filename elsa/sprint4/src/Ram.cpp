#include "Ram.h"


Ram::Ram(std::string n, double c, int g):Options (n,c), _gb(g)
{
   
}
Ram::~Ram(){}

std::string Ram::to_string() const
{
    return _name + "$ "+ std::to_string(_cost) +" at " + std::to_string(_gb)+" Gb";
}
void Ram::save(std::ostream& ost)const
{
    ost<<_name<<std::endl;
    ost<<_cost<<std::endl;
    ost<<_gb<<std::endl;
}
Ram* Ram::ptr() const
{
    return new Ram{*this};
}

