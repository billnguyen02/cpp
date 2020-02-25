#ifndef ___PRODUCT__H
#define ___PRODUCT__H


#include <iostream>
#include <string>

class Product
{
    protected:
        int _quantity;
        double _cost;
        std::string _name;

    public:
         Product( std::string name, double cost);
         
         virtual ~Product() = 0;
         void set_quantity(int quantity);
         virtual  double price() const = 0;
         friend std::ostream& operator<<(std::ostream& ost, const Product& product);

};


#endif