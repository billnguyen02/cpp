#include "color.h"


Color::Color(int r, int g, int b):_red{r}, _green{g}, _blue{b}
{
    //constructor
}

std::string Color::to_string ()
{
  return "("+std::to_string(_red)+","+std::to_string(_green)+","+std::to_string(_blue)+")";
}

std::string Color::colorize (std::string text)
{
  return "\033[38;2;"+std::to_string(_red)+";"+std::to_string(_green)+";"+std::to_string(_blue)+"m"+text+"\033[0m";
}
