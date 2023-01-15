#include "controller.h"
#include <iostream>
#include "SDL.h"

void Controller::HandleInput(bool &running,Dinosaur &dino) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    }
    else if (e.type == SDL_KEYDOWN) {
          // Jump the dinosaur when the space bar is pressed
          if (e.key.keysym.sym == SDLK_SPACE)
          {
              dino.init_jump = true;
          }
    }
  }
}