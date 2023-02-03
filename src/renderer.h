#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "dinosaur.h"
#include "platform.h"

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer() ;

  void Render(Dinosaur dinosaur,Platform &platform1, Platform &platform2);
  void UpdateWindowTitle();
  void RenderPlatform(Platform &platform, SDL_Rect block);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif