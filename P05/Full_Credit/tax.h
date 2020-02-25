#ifndef ___TAXED__H
#define ___TAXED__H
#include "product.h"


class Taxed : public Product
{

    private:
        static double _tax;
    public: 
        Taxed(std::string name, double cost);
        virtual ~Taxed();
        static void set_tax_rate(double sale_tax);
        virtual double price() const override;
       
};



#endif