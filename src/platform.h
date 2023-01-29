#ifndef PLATFORM_H
#define PLATFORM_H
#include <iostream>
// #include "SDL.h"


class Platform {
 public:
   Platform(int grid_width, int grid_height, int posx, std::string image_path): 
   width(grid_width),
   pos_y(static_cast<int>(0.6*grid_height)),
   pos_x(posx),
   image_path(image_path) {}
   void update();
   int pos_y;
   int pos_x;
   int width;
   //int height;
   std::string image_path;
};

#endif