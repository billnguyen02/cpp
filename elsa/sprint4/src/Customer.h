#ifndef __CUSTOMER__H
#define __CUSTOMER__H

#include <string>

class Customer
{
    private:
        std::string _name;
        std::string _phone;
        std::string _email;
    public:
        Customer(std::string name, std::string phone,std::string email);
        friend std::ostream& operator<<(std::ostream& ost, const Customer& Cus);
        void save(std::ostream& ost);
        Customer(std::istream& ist);
        std::string search();
};

#endif