#include "Store.h"

void Store::add_customer(Customer& add_customer)
{
    vector_customers.push_back(add_customer);
}
int Store::num_customers()
{
    return vector_customers.size();
}
Customer& Store::customer(int index)
{
    
    return vector_customers.at(index);
}

///////////OPTIONS

void Store::add_option(Options& add_option)
{
    //Option is a vector pointer so allocation memory for it.
    Options* ptr_option = new Options{add_option};
    vector_Options.push_back(ptr_option);
}
int Store::num_options()
{
    //return the size of vector Options
    return vector_Options.size();
}
Options& Store::option(int index)
{
    //return the vector option at that index but option is a vector POINTER
    Options* ptr_option = vector_Options.at(index);
    return *ptr_option;
}

////////////////DESKTOPS///////

int Store::new_desktop()
{
    //There isnt a constructor for desktop so we can instance it using the DEFAULT CONSTRUCTOR
    Desktop desktops ;
    vector_desktops.push_back(desktops);

    return vector_desktops.size()-1;
}
Desktop& Store::desktop(int index)
{ ;
    return vector_desktops.at(index);
}
void Store::add_option(int option, int desktop)
{
    //No & by vector because option its a vector pointer
    Options *ptr_option = vector_Options.at(option);
    // the & is for us to use the actual value not the copy
    Desktop &location_desktop = vector_desktops.at(desktop);
    
    location_desktop.add_option(*ptr_option);
    double total_price = location_desktop.price();
    std::cout<<"\n YOUR CART: "<<total_price<<"$\n\n";
}
int Store::num_desktops()
{
    int size = vector_desktops.size();
    return size;
}

/////////////////ORDER
int Store::new_order(int customer)
{
    Order cus{vector_customers.at(customer)};
    Order &add_cus = cus;
    vector_orders.push_back(add_cus);
    return vector_orders.size()-1;
}
void Store::add_desktop(int desktop, int order)
{
  Order &location_order = vector_orders.at(order);
  Desktop *desk = &vector_desktops.at(desktop);
  
  int size = location_order.add_product(*desk);
  if(size>0)
  {
    double total_price = location_order.price();
    std::cout<<"\nTOTAL ORDER PRICE: "<< total_price<<"$"<<std::endl<<std::endl;
  }
}
int Store::num_orders()
{
    int size = vector_orders.size();
    return size;
}
Order& Store::order(int index)
{
    return vector_orders.at(index);
}
