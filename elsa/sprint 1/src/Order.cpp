
#include "Order.h"

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
    ost<<"CUSTOMER ORDER: \n";
    for(Desktop*  ptr_order: add_order._products)
    {
        ost << *ptr_order << "\n";
    }
    ost<<"CONTACT INFO: \n"<<add_order._customer;
    return ost;
   
}
