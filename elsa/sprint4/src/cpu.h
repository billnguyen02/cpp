#ifndef ___CPU__H
#define ___CPU__H
#include <string>
#include "Options.h"
class CPU : public Options
{
    protected: 
        std::string _core;

    public:
        CPU(std::string name, double cost, std::string core);
        virtual ~CPU();
   
        std::string to_string() const override ;
        virtual void save(std::ostream& ost) const override;
        CPU* ptr() const override ;
        CPU(std::istream& ist);
        CPU();
};

#endif