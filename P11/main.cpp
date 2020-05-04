#include "Item.h"
#include "Cart.h"
#include <iostream>

int main(){
    std::cout << "Enter product names and price  (e.g., English peas 0.79 ):" << std::endl;
    std::string line;
    Item null{"",0.000};
    Cart cart{"BILL"};
    try{
        while(std::cin >> null)
        {
            cart.add_item(null);
            std::cout<<("Added----")<<std::endl;
        }
 
    }
    catch(std::exception &e)
    {
        
        std::cin.ignore();
    }
    
    for(std::vector<Item*>::iterator p = cart.begin(); p!= cart.end(); p++ )
    {
        std::cout << *p <<std::endl;
    }
}