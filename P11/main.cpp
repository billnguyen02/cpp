#include "Item.h"
#include "Cart.h"
#include <iostream>

int main(){
    std::cout << "Enter product names and price  (e.g., English peas 0.79 ):" << std::endl;
    std::string line;
    Item null{"",0.000};
    Cart cart{"BILL"};
    while(std::cin >> null)
    {
        cart.add_item(null);                     
    }
 
    std::cout<< "\nRegister Receipt\n"<<std::endl;

    for(std::vector<Item*>::iterator p = cart.begin(); p!= cart.end(); p++ )
    {
        std::cout << *p ;
    }
    double total;
    total = cart.cost();
    std::cout<<"------------------------------"<<std::endl;
    std::cout<< "$      "<<std::setprecision(4)<<total<<"   Total Cost";

}