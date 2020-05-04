#ifndef ___ITEM__H
#define ___ITEM__H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <exception>

class Item
{
    private:
        std::string _name;
        double _price;
    public:
        Item();
        Item(std::string name, double price);
        double cost();
        friend std::ostream& operator<<(std::ostream& ost, Item* item);
        friend std::istream& operator>>(std::istream& ist, Item& item);
};

#endif