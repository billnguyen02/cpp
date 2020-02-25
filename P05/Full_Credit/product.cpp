#include "product.h"
#include <string.h>
#include <iostream>

//int Product::price{0};

Product::Product(std::string name, double cost): _name{name},_cost{cost},_quantity{0} // creating the object
{
    //Constructor
}
Product::~Product()
{
    //destructor for Product object
}
void Product::set_quantity(int quantity)// set quantity for protected quantity
{
     Product::_quantity = quantity;
}
std::ostream& operator<<(std::ostream& ost, const Product& product)
{
    
    
    if(product._quantity > 0)
    {
        ost<<product._name<<" ("<<product._quantity<<" @ $"<<product._cost<<")"<<std::endl;
        return ost;
    }
    else
    {
        ost<< product._name<<" ($"<<product._cost<<")"<<std::endl;
        return ost;
    }
    

}



