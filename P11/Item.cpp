#include "Item.h"

#include "Item.h"
Item::Item(){}
Item::Item(std::string n,double p):_name(n),_price(p){}
double Item::cost(){return _price;};
std::ostream& operator<<(std::ostream& ost,  Item* item)
{   
    
    ost<<"Item name "<< item->_name<<" "<<"$"<< item->_price<<std::endl; return ost;
}
std::istream& operator>>(std::istream& ist, Item& item)
{
    std::string line;
    std::vector<std::string> str;
    int size;
    std::string word;
    
    std::getline(ist,line);
    
        
           std::istringstream ss(line);
            while(getline(ss,word,' '))
                {
                 str.push_back(word);
                }
            size = str.size();
  
            for(int i = 0 ; i < size-1; i ++)
                {
                    item._name = item._name + " " + str.at(i);
                    std::cout<<item._name<<" ";
                } 
           
            try{        
                double num = std::stod(str.at(size-1));
                item._price = num;
                std::cout<< "PRICE = "<< std::setprecision(5) << num << std::endl;     
            }
            catch(std::exception& e)
            {
                     std::cout<<"Invalid price: "<<std::endl;
                    //  std::cout<<"' ";
                    //  for(int i = 0; i< size - 1; i ++)
                    //  {  
                    //     std::cout<<str.at(i)<<" ";
                    //  }
                    //  std::cout<<"'";
                    //  std::cout <<" ==> "<<"'"<< str.at(size-1)<<"'"<<std::endl;   
            }
           return ist;
    
 
  
}