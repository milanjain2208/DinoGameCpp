#ifndef DINO_H
#define DINO_H
#include <iostream>


class Dinosaur {
 public:
   Dinosaur(int grid_width, int grid_height): 
   grid_width(grid_width), grid_height(grid_height),
   pos_x(static_cast<int>(grid_width/50)),
   pos_y(static_cast<int>(static_cast<int>(0.6*grid_height))) {}

   int pos_x;
   int pos_y;
   int width;
   int height;
   std::string image_path = "../media/dino-right.png";
  private:
  int grid_width;
  int grid_height;

};

#endif