#include "color.h"

Color::Color()
{
  _reset = true;
}
Color::Color(int r, int g, int b):_red{r}, _green{g}, _blue{b}
{
    //constructor
    _reset = false;

}


std::string Color::to_string ()
{
  return "("+std::to_string(_red)+","+std::to_string(_green)+","+std::to_string(_blue)+")";
}

std::ostream& operator<<(std::ostream& ost, const Color& color)
{
      if(color._reset == false)
      {
        ost << "\033[38;2;"+std::to_string(color._red)+";"+std::to_string(color._green)+";"+std::to_string(color._blue)+"m";
      }
      if(color._reset == true)
      {
        ost << "\033[0m";
      }



  return ost;
}

std::istream& operator>>(std::istream& ist, Color& color)
{
    ist.ignore(1,'(');
    ist >> color._red;
    ist.ignore(1,',');
    ist >>color._green;
    ist.ignore(1,',');
    ist >>color._blue;
    ist.ignore(1,')');

    color = Color{color._red,color._green, color._blue};
    return ist;

}
//}
