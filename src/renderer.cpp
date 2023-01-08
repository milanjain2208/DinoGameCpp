#include "renderer.h"
#include <iostream>
#include <string>

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height,
                   const std::size_t grid_width, const std::size_t grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Dino Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::Render(Dinosaur dinosaur) {
  SDL_Rect block;
  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderClear(sdl_renderer);

  // Render line
  SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x00, 0x00, 0xFF);
  SDL_Point point{0,static_cast<int>(0.6*grid_height)};

  SDL_RenderDrawLine(sdl_renderer,0,point.y*block.h,static_cast<int>(grid_width)*block.w,point.y*block.h);

  // Render Dinosaur
  SDL_Surface* surface = IMG_Load(dinosaur.image_path);
  if (!surface)
  {
      std::cout << "Failed to load image: " << SDL_GetError() << std::endl;
  }

  // Create a texture from the surface
  m_texture = SDL_CreateTextureFromSurface(sdl_renderer, surface);
  if (!m_texture)
  {
      std::cout << "Failed to create texture: " << SDL_GetError() << std::endl;
  }
  SDL_Rect dest;
  dest.x = dinosaur.pos_x;
  dest.y = dinosaur.pos_y;
  dest.w = surface->w;
  dest.h = surface->h;

  SDL_RenderCopy(renderer, m_texture, NULL, &dest);

  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle() {
  std::string title{"Game is on"};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
