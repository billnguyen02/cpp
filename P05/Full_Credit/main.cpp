#include "product.h"
#include "tax.h"
#include "taxfree.h"
#include <iostream>
#include <vector>
#include <iomanip> 

int main()
{   
    Taxed::set_tax_rate(0.08);
    
    Taxed Ticket{"Coachella",498.2};
    Taxed Cruise{"Holy SHip",198.25};
    Taxed Rave{"EDC",500.63};

    Taxfree Coffee{"Starbuck", 4.5};
    Taxfree Drug("Cough Medicine",20);
    Taxfree Aid("Bandage",5);
    
    int ans_quan;
    int ans_index;
    std::vector <int> Array; 
    std::vector <int>  Array2;
    int count=0;
    int count2 = 0;
    int i;
    double x =0;
    double ticket,cruise,rave,coffee,drug,aid;
   
    bool stop = false;
    std::vector<Taxed> Taxed{Ticket,Cruise,Rave};
    std::vector<Taxfree>Tax_free{Coffee,Drug,Aid};
    while(!stop)
    {
         std::cout<<"==========================\n"<<std::endl;
         std::cout<<"  WELCOME TO THE STORE\n"<<std::endl;
         std::cout<<"==========================\n"<<std::endl;
         std::cout<<"0) ";
         
         std::cout<<Ticket;
         std::cout<<"1) ";
         
         std::cout<<Cruise;
         std::cout<<"2) ";
       
         std::cout<<Rave;
         std::cout<<"3) ";
         
         std::cout<<Coffee;
         std::cout<<"4) ";
         
         std::cout<<Drug;
         std::cout<<"5) ";
         
         std::cout<<Aid;     

         std::cout<<"Enter quantity ( 0 to exit ) and product index: ";
         std::cin>>ans_quan;
         std::cin>>ans_index;
         if(ans_quan == 0)
         {
             break;
         }
         std::cout<<"\n\n Current order\n";
         std::cout<<"---------------------------\n";
         if(ans_index == 0)
             {
                
                //Taxed.push_back(Ticket);
                Taxed[0].set_quantity(ans_quan);
              //  std::cout<<Taxed[0];
                Array.push_back(0);
                ticket = Taxed[0].price();
                x = x+ticket;
                count++;
                
             }
         else if(ans_index == 1)
             {
                //Taxed.push_back(Cruise);
                Taxed[1].set_quantity(ans_quan);
              //  std::cout<<Taxed[1];
                Array.push_back(1);
                cruise = Taxed[1].price();
                x=x+cruise;
                count++;
             }
         else if(ans_index == 2)
             {
                //Taxed.push_back(Rave);
                Taxed[2].set_quantity(ans_quan);
               // std::cout<<Taxed[2]; 
                Array.push_back(2);  
                rave = Taxed[2].price();
                x=x+rave;
                count++;             
             }    
         else if(ans_index == 3)
             {
               // Tax_free.push_back(Coffee);
                Tax_free[0].set_quantity(ans_quan);
                //std::cout<<Tax_free[0]; 
                Array2.push_back(0);
                coffee = Tax_free[0].price();
                x=x+coffee;
                count2++;              
             }
         else if(ans_index == 4)
             {
               // Tax_free.push_back(Drug);
                Tax_free[1].set_quantity(ans_quan);
               // std::cout<<Tax_free[1]; 
                Array2.push_back(1); 
                drug=Tax_free[1].price();
                x=x+drug;
                count2++;               
             }   
         else if(ans_index == 5)
             {
               // Tax_free.push_back(Aid);
                Tax_free[2].set_quantity(ans_quan);
               // std::cout<<Tax_free[2];
                Array2.push_back(2); 
                aid=Tax_free[2].price();
                x=x+aid;

                count2++;               
             } 
        if(count>0)
        {
        for(i=0;i<count;i++)
            {
                std::cout<<Taxed[Array[i]];
            }
        }
        if(count2>0)
        {
        for(i=0;i<count2;i++)
        {
                std::cout<<Tax_free[Array[i]];
        }
       
       }
       std::cout<<"\n\nTotal Price "<<x<<std::endl;

       
       }
   
}












