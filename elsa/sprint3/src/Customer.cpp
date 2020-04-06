#include "Customer.h"
#include <iostream>

Customer::Customer(std::string name, std::string phone, std::string email) : _name(name),_phone(phone),_email(email)
{
    //Constructor
}
std::ostream& operator<<(std::ostream& ost, const Customer& Cus)
{
    ost<<"Customer information:\n";
    return ost<<"Name:"<< Cus._name 
              <<"\nPhone number:"<< Cus._phone
              <<"\nEmail: "<< Cus._email
              <<std::endl;
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