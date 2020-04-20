#include "Disk.h"


Disk::Disk(std::string n, double c, double num,std::string type):Options (n,c), _storage(num),_type(type)
{
   
}
Disk::Disk(){}
Disk::~Disk(){}

std::string Disk::to_string() const
{
    return _name + "$ "+ std::to_string(_cost) +"\nCapacity: " + std::to_string(_storage)+ " ("+_type+")";
}
void Disk::save(std::ostream& ost)const
{
    ost<<"D"<<std::endl;
    ost<<_name<<std::endl;
    ost<<_cost<<std::endl;
    ost<<_storage<<std::endl;
    ost<<_type<<std::endl;
}
Disk* Disk::ptr() const
{
    return new Disk{*this};
}
Disk::Disk(std::istream& ist)
{
    std::string text,name,cost,num,type;
    getline(ist,text);
    getline(ist,name);
    getline(ist,cost);
    getline(ist,num);
    getline(ist,type);
    
    double num_cost = stod(cost);
    double    amount  = stod(num);
    
    _name = name;
    _cost = num_cost;
    _storage = amount;
    _type = type;
    
}

