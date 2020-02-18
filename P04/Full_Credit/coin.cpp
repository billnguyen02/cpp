#include "coin.h"

//#define LOG(msg)
    //std::cerr<<__FILE__<<"("<<__Line__<<"):"<<msg<<std::endl


const std::map<Coin_Size,std::string> sizes={
    {Penny,"penny"},
    {Dime,"dime"},
    {Nickle,"nickle"},
    {Quarter,"quarter"}
};

Coin::Coin(Coin_Size size, Year year): _size{size},_year{year},_note{NULL}
{
    LOG ("Coin:Coin");
}

Coin::Coin(const Coin&rhs):_size(rhs._size),_year{rhs._year}
{
     _note = new std::string;
     *_note = *rhs._note;
     LOG ("COIN::Coin copy constructor ");
}

 Coin &Coin::operator= (const Coin& rhs)
 
{
        _size = rhs._size;
        _year = rhs._year;
        _note = new std::string;
        *_note = *rhs._note;
        LOG ("COIN::Coin operator = ");
        
}
 void Coin::add_note(std::string s)
 {
     if(!_note)
     {
           _note = new std::string[s.length()];
           *_note = s;
     }
     else
     {
        *_note = *(_note) + s;
     }
     
 }

 std::ostream& operator<<(std::ostream& ost, const Coin& coin)
 {
    try
    {
        ost << coin._year << " " << sizes.at(coin._size) << '\n' << *coin._note;
    }
     catch (std::exception )
     {
         std::cout<<"ERROR";
     }
     
     return ost;
 }
 Coin::~Coin()
{
    delete _note;
    LOG ("Coin::~Coin");
}



