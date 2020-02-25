#ifndef ___TAXEFREE__H
#define ___TAXEFREE__H
#include "product.h"


class Taxfree : public Product
{
    public:
        Taxfree(std::string name, double cost);
        virtual ~Taxfree() ;
        virtual double price() const override ; 
};

#endif