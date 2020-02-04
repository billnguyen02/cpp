
#include <iostream>
#include "color.h"

int main()
{
      int x,y,z;
      Color Red{255,0,0};
      Color ArmyGreen{59,122,87};
      Color Blue {0,35,102};

        std::cout << Red.colorize("RED ") << ArmyGreen.colorize("ARMY-GREEN ")<< Blue.colorize ("BLUE")<<std::endl;
        std::cout <<("Enter red, green, blue int ")<<std::endl;
        std::cin >> x >> y >> z ;

      Color Random(x,y,z);
        std::cout <<Random.colorize("("+std::to_string(x)+","+std::to_string(y)+","+std::to_string(z)+")")<<std::endl;
}
