#ifndef __COIN_H
#define __COIN_H
#include "logger.h"
#include <iostream>
#include <string>
#include <map>



typedef int Year;

enum  Coin_Size
{
    Penny,
    Nickle,
    Dime,
    Quarter,

};

class Coin
{
    private:
        Coin_Size _size;
        Year _year;
        std::string *_note;
    public:
         Coin(Coin_Size size, Year year);
         Coin(const Coin& rhs);
         Coin &operator=(const Coin& rhs);
         ~Coin();
         void add_note(std::string s);
         friend std::ostream& operator<<(std::ostream& ost, const Coin& coin);
         friend std::istream& operator>>(std::istream& ist, Coin& coin);

};


#endif
