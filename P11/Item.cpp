#include "Item.h"


Item::Item(){}
Item::Item(std::string n,double p):_name(n),_price(p){}
double Item::cost(){return _price;};
std::string Item::name(){return _name;};
std::ostream& operator<<(std::ostream& ost,  Item* item)
{   
    
    ost<<"$      "<<std::setprecision(4)<<item->_price<<"   "<<item->_name<<std::endl; return ost;
}
std::istream& operator>>(std::istream& ist, Item& item)
{
    std::string line;
    std::vector<std::string> str;
    int size;
    std::string word;
    item._name = "";
    std::getline(ist,line);
    if(line.length() == 0){ return ist ;}
        
           std::istringstream ss(line);
            while(getline(ss,word,' '))
                {
                  str.push_back(word);
                }
            size = str.size();
  
            for(int i = 0 ; i < size-1; i ++)
                {
                    item._name = item._name + " " + str.at(i);                   
                } 
           
            try{        
                double num = std::stod(str.at(size-1));
                item._price = num;
                str.clear();
                return ist;                 
            }
            catch(std::exception& e)
            {
                     std::cout<<"Invalid price: ";
                      std::cout<<"' ";
                      for(int i = 0; i< size - 1; i ++)
                      {  
                         std::cout<<str.at(i)<<" ";
                      }
                      item._name ="NULL";
                      std::cout<<"'";
                      std::cout <<" ==> "<<"'"<< str.at(size-1)<<"'"<<std::endl;   
            }
           return ist;
    
 
  
}