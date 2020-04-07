
#include "Order.h"
// #include <iostream>
 #include <sstream>
Order::Order(Customer& add_customer):_customer{&add_customer}
{
    

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
   
    ost<<"CONTACT INFO: \n"<<*add_order._customer;
    return ost;
}
void Order::save(std::ostream& ost)
{
    ost << _products.size()<<std::endl;
    int size;
    size = _products.size();
     

    ost << *_customer;
    for(int i = 0; i<size ; i++)
    {
        ost << *_products.at(i);
    }
}
Order::Order(std::istream& ist)
{

    int product_size;
    ist >> product_size;
    ist.ignore(32767,'\n');

         std::string text,name,email,phone;
        getline(ist,text);
        getline(ist,name);
        getline(ist,email);
        getline(ist,phone);
        Customer customer {name,email,phone}; 
        Customer* ptr_customer = new Customer{customer};
        _customer = ptr_customer;

        

         for( int k = 0; k < product_size ; k++)
          {
              std::string d_list,option,cost,line,line2;
              getline(ist,d_list);
              getline(ist,line);
              //getline(ist,line2);
              std::stringstream os;
              os << line;
              os >> option >> cost;
              double val;
              val = std::stod(cost);

              Options* o= new Options{option,val};
              Desktop desktop;
              desktop.add_option(*o);
              Desktop* ptr_desktop = new Desktop{desktop};
              _products.push_back(ptr_desktop);
          }
        //_products.push_back(customer);
    
}

