#ifndef __STORE_H
#define __STORE_H

#include "Customer.h"
#include "Options.h"
#include "Desktop.h"
#include "Order.h"

class Store {
  public:
    Store();
    void save(std::ostream& ost);
    Store(std::istream& ist);
    void add_customer(Customer& customer);
    int num_customers();
    Customer& customer(int index);

    void add_option(Options& option);
    int num_options();
    Options& option(int index);

    int new_desktop(); // returns index
    void add_option(int option, int desktop); // to desktop
    int num_desktops();
    Desktop& desktop(int index);

    int new_order(int customer); // returns order number
    void add_desktop(int desktop, int order); // to order
    int num_orders();
    Order& order(int index);
  private:
    
    std::vector<Customer> customers;
    std::vector<Options*>  options;
    std::vector<Desktop>  desktops;
    std::vector<Order>    orders;
};

#endif
