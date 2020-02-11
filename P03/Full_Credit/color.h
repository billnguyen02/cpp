#ifndef __COLOR_H
#define __COLOR_H
#include <string>
#include <iostream>
#include <sstream>

class Color {

  int _red;
  int _blue;
  int _green;
  bool _reset;

  public:

    Color(int r, int g, int b);
    Color();
    std::string to_string();
    friend std::ostream& operator<<(std::ostream& ost, const Color& color);
    friend std::istream& operator>>(std::istream& ist, Color& color);


};

//std::istream& operator>>(std::istream& ist, Color& color) ;



#endif
