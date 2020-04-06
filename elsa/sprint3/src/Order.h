#ifndef ___ORDER__H
#define ___ORDER__H

#include "Customer.h"
#include "Desktop.h"
#include <string>
#include <iostream>
#include <vector>

class Order 
{
    private:
        Customer _customer;
        std::vector <Desktop*> _products;
    public:
        Order(Customer& add_customer);
        ~Order();
        int add_product(Desktop& add_desktop);
        double price();
        friend std::ostream& operator<<(std::ostream& ost, const Order& add_order);
        //Order(std::istream& ist);
        void save(std::ostream& ost);

};





#endif