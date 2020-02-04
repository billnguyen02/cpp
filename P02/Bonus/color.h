#ifndef __COLOR_H
#define __COLOR_H
#include <string>
#include <cmath>



class Color {

  int _red;
  int _blue;
  int _green;


  public:
    Color(int r, int g, int b);
    std::string to_string();
    std::string colorize(std::string text);
    int magnitude();
  //  int compare(const Color & rhs);
};

#endif
