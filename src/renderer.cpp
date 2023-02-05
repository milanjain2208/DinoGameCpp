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

void Renderer::Render(Dinosaur dinosaur, Platform &platform1, Platform &platform2) {
  SDL_Rect block;
  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;

  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  SDL_RenderClear(sdl_renderer);

  // RenderPlatform(platform1,block);
  // RenderPlatform(platform2,block);
  platform1.render(sdl_renderer,block);
  platform2.render(sdl_renderer,block);

  dinosaur.render(sdl_renderer,block);
  // // Render Dinosaur
  // SDL_Surface* surface = SDL_LoadBMP(dinosaur.image_path.c_str());
  // if (!surface)
  // {
  //     std::cout << "Failed to load image: " << SDL_GetError() << std::endl;
  // }

  // // Create a texture from the surface
  // SDL_Texture* m_texture = SDL_CreateTextureFromSurface(sdl_renderer, surface);
  // if (!m_texture)
  // {
  //     std::cout << "Failed to create texture: " << SDL_GetError() << std::endl;
  // }
  // SDL_Rect dest;
  // dest.x = dinosaur.pos_x * block.w;
  // dest.y = dinosaur.pos_y * block.h - (surface->h/2);
  // dest.w = surface->w/2;
  // dest.h = surface->h/2;

  // SDL_RenderCopy(sdl_renderer, m_texture, NULL, &dest);

  // // Update Screen
  // SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle() {
  std::string title{"Game is on"};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}

// void Renderer::RenderPlatform(Platform &platform, SDL_Rect block) {
//     // std::cout << platform.grid_height << std::endl;
//     SDL_Surface* platform_surface = SDL_LoadBMP(platform.image_path.c_str());
//     if (!platform_surface)
//     {
//         std::cout << "Failed to load platform image: " << SDL_GetError() << std::endl;
//     }

//     // Create a texture from the surface
//     SDL_Texture* platform_texture = SDL_CreateTextureFromSurface(sdl_renderer, platform_surface);
//     if (!platform_texture)
//     {
//         std::cout << "Failed to create platform texture: " << SDL_GetError() << std::endl;
//     }
//     SDL_Rect platform_rect;
//     platform_rect.x = platform.pos_x * block.w;
//     platform_rect.y = platform.pos_y * block.h;
//     platform_rect.w = platform.width;
//     platform_rect.h = platform_surface->h;
//     SDL_RenderCopy(sdl_renderer, platform_texture, NULL, &platform_rect);

//     // Render tree
//     SDL_Surface* tree_surface = SDL_LoadBMP(platform.tree.image_path.c_str());
//     if (!tree_surface)
//     {
//         std::cout << "Failed to load image: " << SDL_GetError() << std::endl;
//     }

//     // Create a texture from the surface
//     SDL_Texture* tree_texture = SDL_CreateTextureFromSurface(sdl_renderer, tree_surface);
//     if (!tree_texture)
//     {
//         std::cout << "Failed to create texture: " << SDL_GetError() << std::endl;
//     }
//     SDL_Rect tree_rect;
//     tree_rect.x = platform.tree.pos_x * block.w;
//     tree_rect.y = platform.tree.pos_y * block.h - (tree_surface->h);
//     tree_rect.w = tree_surface->w;
//     tree_rect.h = tree_surface->h;

//     SDL_RenderCopy(sdl_renderer, tree_texture, NULL, &tree_rect);
// }
