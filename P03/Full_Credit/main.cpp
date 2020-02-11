
#include <iostream>
#include "color.h"

int main()
{
      Color Random;
      Color reset;
      Color Red{255,0,0};
      Color ArmyGreen{59,122,87};
      Color Blue {0,35,102};




      // operator<<(operator<<(std::cout, Red), "RED");
       std::cout << Red << "RED " << ArmyGreen <<"Army Green "<< Blue <<"Blue"<< reset <<std::endl;

      // std::cout << ArmyGreen << "GREEN" << std::endl;
      // std::cout << Red << std::endl;

       std::cout <<("Enter red, green, blue int ")<<std::endl;
       std::cin >> Random;


       std::cout << Random << Random.to_string();        //std::cout <<Random.colorize("("+std::to_string(x)+","+std::to_string(y)+","+std::to_string(z)+")")<<std::endl;
}
