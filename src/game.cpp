#include <iostream>
#include "game.h"

// Game::Game(std::size_t grid_width, std::size_t grid_height):
//     dinosaur(grid_width, grid_height) {}
void Game::Run(Controller &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running,dinosaur);
    Update();
    renderer.Render(dinosaur,platform1, platform2);
    // std::cout<<dinosaur.dest.x<<" "<<dinosaur.dest.y<<" "<<dinosaur.dest.w<<" "<<dinosaur.dest.h<<" "<<std::endl;
    // std::cout<<platform1.tree.dest.x<<" "<<platform1.tree.dest.y<<" "<<platform1.tree.dest.w<<" "<<platform1.tree.dest.h<<" "<<std::endl;
    if (Collision(dinosaur.dest,platform1.tree.dest) || Collision(dinosaur.dest,platform2.tree.dest)) {
      std::cout << "Terminating" << std::endl;
      running = false;
    }

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score);
      frame_count = 0;
      score++;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::Update() {
//   if (!snake.alive) return;

  dinosaur.update();
  platform1.update();
  platform2.update();
}

int Game::GetScore() const { return score; }

  bool Game::Collision(SDL_Rect a, SDL_Rect b) {
    // std::cout<<a.x<<"  " <<b.x<<std::endl;
    return SDL_HasIntersection(&a, &b);
  }