#ifndef ___DISK__H
#define ___Disk__H
#include <string>
#include "Options.h"
class Disk : public Options
{
    protected: 
        double _storage;
        std::string _type;

    public:
        Disk(std::string name, double cost, double num, std::string type );
        virtual ~Disk();
      
        std::string to_string() const override ;
        virtual void save(std::ostream& ost) const override;
        Disk* ptr() const override ;
        Disk(std::istream& ist);
        Disk();
};

#endif