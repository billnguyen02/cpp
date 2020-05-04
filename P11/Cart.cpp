#include"Cart.h"
Cart::Cart(std::string c):_customer(c){}
Cart::~Cart(){}
Cart::Cart(const Cart& cart): _customer{cart._customer}{
    for(Item* i : cart._item)
        _item.push_back ( new Item{*i} );
}
void Cart::add_item(Item &item)
{
    _item.push_back(new Item{item});
}
double Cart::cost()
{
    int size = _item.size();
    double sum = 0;
    for(int i = 0 ; i < size; i++)
    {
        sum += _item.at(i)->cost();
    }
    return sum;
}
std::vector<Item*>::iterator Cart::begin()
{
    return _item.begin();
}
std::vector<Item*>::iterator Cart::end()
{
    return _item.end();
}
