#ifndef __CART_H
#define __CART_H
#include <vector>
#include "Item.h"
#include <string>
class Cart
{
    private:
        std::string _customer;
        std::vector <Item*> _item;
    public:
        Cart(std::string customer);
        ~Cart();
        Cart(const Cart &cart);
        Cart& operator = (const Cart &cart);
        void add_item(Item& item);
        double cost();
        std::vector<Item*>::iterator  begin();
        std::vector<Item*>::iterator  end();

};

#endif