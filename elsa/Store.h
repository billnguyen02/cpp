#ifndef ___STORE__H
#define ___STORE__H

#include <iostream>
#include <string>
#include <vector>
#include "Customer.h"
#include"Options.h"
#include "Desktop.h"
#include "Order.h"

class Store
{
    private:
        std::vector <Customer> vector_customers;
        std::vector <Options * > vector_Options;
        std::vector <Desktop  > vector_desktops;
        std::vector <Order> vector_orders;
    public:
        void add_customer(Customer& add_customer);
        int num_customers();
        Customer& customer(int index);
        ///////
        void add_option(Options& add_option);
        int num_options();
        Options& option(int index);
        ///////
        int new_desktop();
        void add_option(int option, int desktop);
        Desktop& desktop(int index);
        int num_desktops();
        ///////
        int new_order(int customer);
        void add_desktop(int desktop, int order);
        int num_orders();
        Order& order( int index);

};

#endif
