#include "cpu.h"


CPU::CPU(std::string n, double c,  std::string core):Options (n,c), _core(core)
{
   
}
CPU::CPU(){}
CPU::~CPU(){}

std::string CPU::to_string() const
{
    return _name + "$ "+ std::to_string(_cost) +" at " + _core+" Core";
}
void CPU::save(std::ostream& ost)const
{
    ost<<"C"<<std::endl;
    ost<<_name<<std::endl;
    ost<<_cost<<std::endl;
    ost<<_core<<std::endl;
}
CPU* CPU::ptr() const
{
    return new CPU{*this};
}
CPU::CPU(std::istream& ist)
{
    std::string text,name,cost,core;
    getline(ist,text);
    getline(ist,name);
    getline(ist,cost);
    getline(ist,core);
    
    double num_cost = stod(cost);
   
  //  Ram Ram {name,num_cost,num_gb};
    _name = name;
    _cost = num_cost;
    _core = core;
}

