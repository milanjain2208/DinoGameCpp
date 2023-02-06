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

void Renderer::Render(Dinosaur &dinosaur, Platform &platform1, Platform &platform2) {
  SDL_Rect block;
  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderClear(sdl_renderer);

  platform1.render(sdl_renderer,block);
  platform2.render(sdl_renderer,block);

  dinosaur.render(sdl_renderer,block);
}

void Renderer::UpdateWindowTitle(int score) {
  std::string title{"Dino Score: " + std::to_string(score)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
  UpdateScore(score);
}

void Renderer::UpdateScore(int score) {
  TTF_Font* font = TTF_OpenFont("font.ttf", 24);
  if (font == nullptr) {
    std::cerr << "Failed to load font! SDL_ttf Error: " << TTF_GetError() << std::endl;
  }

  // Render text to surface
  SDL_Color textColor = {0, 0, 0, 255};
  std::string text = "12345";
  SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), textColor);
  if (textSurface == nullptr) {
    std::cerr << "Unable to render text surface! SDL_ttf Error: " << TTF_GetError() << std::endl;
  }

  // Create texture from surface
  SDL_Texture* textTexture = SDL_CreateTextureFromSurface(sdl_renderer, textSurface);
  if (textTexture == nullptr) {
    std::cerr << "Unable to create texture from rendered text! SDL Error: " << SDL_GetError() << std::endl;
  }
  SDL_Rect textRect = {0, 0, textSurface->w, textSurface->h};
  SDL_RenderCopy(sdl_renderer, textTexture, nullptr, &textRect);
  SDL_RenderPresent(sdl_renderer);
}