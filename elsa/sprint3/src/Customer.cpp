#include "Customer.h"
#include <iostream>

Customer::Customer(std::string name, std::string phone, std::string email) : _name(name),_phone(phone),_email(email)
{
    //Constructor
}
std::ostream& operator<<(std::ostream& ost, const Customer& Cus)
{
    ost<<"Customer information:\n";
    ost<< Cus._name<<std::endl;
    ost<< Cus._phone<<std::endl;
    ost<< Cus._email<<std::endl;
    return ost;
              
}

void Customer::save(std::ostream& ost) {
     
         ost<< _name <<std::endl;
          ost<< _email <<std::endl;
           ost<< _phone <<std::endl;
}
Customer::Customer(std::istream& ist)
{
    getline(ist,_name);
    getline(ist,_email);
    getline(ist,_phone);
}