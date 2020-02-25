#include "taxfree.h"
#include "product.h"
#include <iostream>
#include <string.h>

Taxfree::Taxfree(std::string name, double cost) : Product(name,cost)// creating the object
{
    //Constructor
}
Taxfree::~Taxfree()
{

}
double Taxfree::price() const
{
    double x;
    x = (_quantity * _cost);
    return x;
}