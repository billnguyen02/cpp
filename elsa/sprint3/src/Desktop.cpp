
#include "Desktop.h"
#include <vector>
#include <iostream>
#include <sstream>


void Desktop::add_option(Options& add_options)
{
    _options.push_back(&add_options);
    
}
int Desktop::size()
{
     return _options.size();
}
std::ostream& operator<<(std::ostream& ost, const Desktop& desktop)
{
    ost<<"Dektop List: \n";
    for(auto ptr_option: desktop._options)
    {
        ost << *ptr_option << "\n";
    }
    
    return ost;
}

double Desktop::price()
{
    double total = 0.0;
    for (auto ptr_option: _options)
    {
        total = total + ptr_option->cost();
    }
    return total;
}
void Desktop::save(std::ostream& ost){
    ost<<_options.size()<<  std::endl;
     for(auto ptr_option: _options)
    {
        ost << *ptr_option << "\n";
    }
}
Desktop::Desktop(){};
Desktop::Desktop(std::istream& ist)
{
        int size = 0;
        ist >> size;
        ist.ignore(32767,'\n');
        for(int i = 0;i< size; i++)
        {
            std::string text;
            getline(ist,text); 
       //ist >>text;
       
            std::string name;
            double val = 0;

            std::stringstream os;
            os << text;
            os >> name >> val;
            Options* options = new Options{name,val};
            _options.push_back(options);
        }
           
}


