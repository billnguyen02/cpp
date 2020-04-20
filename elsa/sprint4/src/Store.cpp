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
void Store::add_option(Options& option)
{
   
   // o = new Options{option};
    options.push_back(option.ptr());    
}
void Store::remove_option(int index)
{
    int size = options.size();
    if(index <= size)
    {
      options.erase(options.begin()+index);
    }

    int size2 = desktops.size();
    for(int i = 0; i < size2;i++)
    {
        desktops.at(i).fix_option(index);      
    }

}

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
    int i;
    int size = customers.size();
    for(i = 0;i<size;i++)
        customers.at(i).save(ost);
     // DESKTOPS
    ost<<options.size()<<std::endl;
    int size2 = options.size();
    for(i = 0; i<size2;i++)
    {
        options.at(i)->save(ost);       
    }
    //DESKTOPS
    ost<<desktops.size()<<std::endl;
    int size_desktop = desktops.size();
    for(i =0 ; i<size_desktop; i++)
    {
        desktops.at(i).save(ost);
       
    } 
    ost<<orders.size()<<std::endl;
    int size_order = orders.size();
    for(i = 0; i < size_order; i++)
    {
        orders.at(i).save(ost);
        
    } 
}
Store::Store(){}
Store::Store(std::istream& ist){
    int size ;
    ist >> size;
    ist.ignore(32767,'\n');

    //CUSTOMER
    if(size != 0)
    {
            for(int i = 0;i<size;i++)
            {
                Customer customer{ist};
                customers.push_back(customer);
                if(!ist) throw std::runtime_error("HAHA");
            }
    }
    // OPTIONS

    int size2 ;
    ist >> size2;
    ist.ignore(32767,'\n');

    
    std::string R_char = "R";
    std::string O_char = "O";
    std::string C_char = "C";
    std::string D_char = "D";
    std::string R;

    if(size2>0)
    {
        for(int i = 0 ; i < size2; i++)
        {
            ist >> R;
            if(R.compare(R_char) == 0)
            {         
                Ram Ram{ist};
                options.push_back(Ram.ptr());
                if(!ist) throw std::runtime_error("R char");
            }
             else if( R.compare(C_char)==0)
            {
                CPU CPU{ist};
                options.push_back(CPU.ptr());
                if(!ist) throw std::runtime_error("C char");
            } 
             else if( R.compare(O_char)==0)
            {
                Options* Option = new Options {ist};
                options.push_back(Option);
                if(!ist) throw std::runtime_error("O char");
            }     
            else if(R.compare(D_char)==0)
            {
                Disk Disk{ist};
                options.push_back(Disk.ptr());
                if(!ist) throw std::runtime_error("D char");
            }     
        }
    }



    int size_desktop;
    //DESKTOP
    ist >> size_desktop;
     ist.ignore(32767,'\n');
    if (size_desktop != 0)
    {
        for(int i = 0; i < size_desktop; i ++)
        {
            Desktop desktop {ist};
            desktops.push_back(desktop);
            if(!ist) throw std::runtime_error("HAHA");
        }
    }
       //ORDER
    int size_order;
    ist >> size_order;
    ist.ignore(32767,'\n');
    if (size_order != 0)
    {
        for(int i = 0; i < size_order; i ++)
        {
            Order o{ist};
            orders.push_back(o);
            if(!ist) throw std::runtime_error("HAHA");
        }
    }  

 



    
}

