#ifndef DINO_H
#define DINO_H
#include <iostream>
#include "SDL.h"


class Dinosaur {
 public:
   Dinosaur(int grid_width, int grid_height): 
   grid_width(grid_width), grid_height(grid_height),
   pos_x(static_cast<int>(grid_width/40)),
   pos_y(static_cast<int>(0.6*grid_height)),
   init_posy(static_cast<int>(0.6*grid_height)),
   jump_accn(0.02*grid_height) {}
   void update();

   int pos_x;
   int pos_y;
   int width;
   int height;
   int init_jump = false;
   std::string image_path = "../media/dino-right.bmp";
  private:
  void jump();
  int grid_width;
  int grid_height;
  // int jump_height;
  int jump_velocity=0;
  int jump_accn;
  int init_posy;
  // int init_jumptime;
  int in_air=false;
};

#endif