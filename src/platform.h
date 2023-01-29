#ifndef PLATFORM_H
#define PLATFORM_H
#include <iostream>
#include <tree.h>
// #include "SDL.h"


class Platform {
 public:
   Platform(int grid_width, int grid_height, int posx, std::string image_path): 
   width(grid_width),
   grid_width(grid_width),
   grid_height(grid_height),
   pos_y(static_cast<int>(0.6*grid_height)),
   pos_x(posx),
   tree(grid_width,grid_height) {}
   void update();
   int pos_y;
   int pos_x;
   int width;
   int grid_width;
   int grid_height;
   //int height;
   std::string image_path;
   Tree tree;
};

#endif