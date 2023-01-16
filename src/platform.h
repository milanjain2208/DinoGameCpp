#ifndef PLATFORM_H
#define PLATFORM_H
#include <iostream>
// #include "SDL.h"


class Platform {
 public:
   Platform(int grid_width, int grid_height): 
   width(grid_width),
   pos_y(static_cast<int>(0.6*grid_height)) {}
//    void update();

   int pos_x = 0;
   int pos_y;
   int width;
   //int height;
   std::string image_path = "../media/platform.bmp";
};

#endif