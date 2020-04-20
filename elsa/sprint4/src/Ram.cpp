#include "Ram.h"


Ram::Ram(std::string n, double c, int g):Options (n,c), _gb(g)
{
   
}
Ram::Ram(){}
Ram::~Ram(){}

std::string Ram::to_string() const
{
    return _name + "$ "+ std::to_string(_cost) +" at " + std::to_string(_gb)+" Gb";
}
void Ram::save(std::ostream& ost)const
{
    ost<<"R"<<std::endl;
    ost<<_name<<std::endl;
    ost<<_cost<<std::endl;
    ost<<_gb<<std::endl;
}
Ram* Ram::ptr() const
{
    return new Ram{*this};
}
Ram::Ram(std::istream& ist)
{
    std::string text,name,cost,gb;
    getline(ist,text);
    getline(ist,name);
    getline(ist,cost);
    getline(ist,gb);
    
    double num_cost = stod(cost);
    int    num_gb  = stoi(gb);
  
    _name = name;
    _cost = num_cost;
    _gb = num_gb;
}

