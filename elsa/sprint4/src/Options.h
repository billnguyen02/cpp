#ifndef ___OPTIONS__H   
#define ___OPTIONS__H

#include <string>
#include <iostream>

class Options
{
    protected:
        std::string _name;
        double _cost;
        std::string _color ;
    public:
       
        Options(std::string name, double cost);
        virtual ~Options();
        double cost();
        virtual  std::string to_string() const  ;
        friend std::ostream& operator<<(std::ostream& ost,  Options& add_option);
        virtual void save(std::ostream& ost) const ;
        Options(std::istream& ist);
        virtual Options* ptr() const;
        Options();
        std::string search();

};


#endif