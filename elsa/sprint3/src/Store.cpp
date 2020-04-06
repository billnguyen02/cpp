#include "Store.h"

//
// Customers
//
void Store::add_customer(Customer& customer) {customers.push_back(customer);}
int Store::num_customers() {return customers.size();}
Customer& Store::customer(int index) {return customers.at(index);}

//
// Options
//
void Store::add_option(Options& option) {options.push_back(new Options{option});}
int Store::num_options() {return options.size();}
Options& Store::option(int index) {return *options.at(index);}

//
// Products
//
int Store::new_desktop() {
    desktops.push_back(Desktop{});
    return desktops.size()-1;
}
void Store::add_option(int option, int desktop) { // to desktop
    desktops.at(desktop).add_option(*options.at(option));
}
int Store::num_desktops() {return desktops.size();}
Desktop& Store::desktop(int index) {return desktops.at(index);}

//
// Orders
//
int Store::new_order(int customer) {
    orders.push_back(Order{customers.at(customer)});
    return orders.size()-1;
}
    
void Store::add_desktop(int desktop, int order) { // to order
    orders.at(order).add_product(desktops.at(desktop));
}
int Store::num_orders() {return orders.size();}
Order& Store::order(int index) {return orders.at(index);}

void Store::save(std::ostream& ost) {
    ost<<customers.size()<<std::endl;
    int size = customers.size();
    for(int i = 0;i<size;i++)
        customers.at(i).save(ost);
}
Store::Store(){}
Store::Store(std::istream& ist){
    int size ;
    ist >> size;
    ist.ignore(32767,'\n');
    if(size == 0)
    {
        Customer customer{ist};
        customers.push_back(customer);
        if(!ist) throw std::runtime_error("HAHA");
    }
    for(int i = 0;i<size;i++)
    {
        Customer customer{ist};
        customers.push_back(customer);
        if(!ist) throw std::runtime_error("HAHA");
    }
    
}

