#include "tax.h"
#include "product.h"
#include <string.h>
#include <iostream>

double Taxed::_tax = 0;
 

Taxed::Taxed(std::string name, double cost): Product(name,cost)// creating the object
{
    //Constructor
}
Taxed::~Taxed()
{

}
void Taxed::set_tax_rate(double sale_tax)
{
    Taxed::_tax = sale_tax;
}
double Taxed::price() const 
{
    double x;
    x = (_quantity * _cost)*(1+_tax);
    return x;
}
