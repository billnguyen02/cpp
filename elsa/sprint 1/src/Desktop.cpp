
#include "Desktop.h"
#include <vector>



void Desktop::add_option(Options& add_options)
{
    _options.push_back(&add_options);
    
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

