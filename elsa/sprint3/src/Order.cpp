
#include "Order.h"
// #include <iostream>
 #include <sstream>
Order::Order(Customer& add_customer) : _customer{add_customer}
{
    //Constructor 
}
Order::~Order()
{
    //Destructor
}
int Order::add_product(Desktop& add_desktop)
{
    _products.push_back(&add_desktop);//ADDING THE NEW DESKTOP INTO VECTOR PRODUCTS
    int size = _products.size();
    return size;
}
double Order::price()
{
    double total = 0.00;
    for(auto ptr_desktop: _products )
    {
        total = total + ptr_desktop->price();
    }
    return total;
}
std::ostream& operator<<(std::ostream& ost, const Order& add_order)
{   
   
    ost << "Customer: " << add_order._customer;
    for(auto p : add_order._products) ost << "\n  " << *p << "\n  Price: $" << p->price() << "\n";
    
    return ost;

   
}
void Order::save(std::ostream& ost)
{
    
    ost << _products.size()<<std::endl;
    ost << _customer<<std::endl;
    for(Desktop*  ptr_order: _products)
    {
        ost << *ptr_order << "\n";
    }
}

