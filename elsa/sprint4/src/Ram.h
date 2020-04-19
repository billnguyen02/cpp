#ifndef ___RAM__H
#define ___RAM__H
#include <string>
#include "Options.h"
class Ram : public Options
{
    protected: 
        int _gb;

    public:
        Ram(std::string name, double cost, int gb);
        virtual ~Ram();
       // Ram(std::istream& ist);
        std::string to_string() const override ;
        virtual void save(std::ostream& ost) const override;
        Ram* ptr() const override ;
        Ram(std::istream& ist);
        Ram();
};

#endif