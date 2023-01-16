#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "dinosaur.h"
#include "platform.h"
//#include "snake.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height):
    dinosaur(grid_width, grid_height) {}
  void Run(Controller &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  //int GetScore() const;
  //int GetSize() const;

 private:
  Dinosaur dinosaur;
  Platform platform;
  //SDL_Point food;

  //std::random_device dev;
  //std::mt19937 engine;
  //std::uniform_int_distribution<int> random_w;
  //std::uniform_int_distribution<int> random_h;

  //int score{0};

  //void PlaceFood();
  void Update();
};

#endif