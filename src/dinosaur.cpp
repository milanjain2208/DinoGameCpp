#include<dinosaur.h>
void Dinosaur::jump() {
    // init_jumptime = SDL_GetTicks();
    jump_velocity = -1 * 0.12 * grid_height;
    in_air = true;
    std::cout<<jump_velocity<<" "<<jump_accn<<" "<<std::endl;
}
void Dinosaur::update() {
    if (init_jump && !in_air) {
        Dinosaur::jump();
        init_jump = false;
    }
    if(in_air) {
        // std::cout << "In Air\n";
        int curr_jumptime = SDL_GetTicks();
        // int time_duration = curr_jumptime - init_jumptime;
        // std::cout << time_duration;
        pos_y = pos_y + jump_velocity ;
        jump_velocity += jump_accn;
        // std::cout<<pos_y<<std::endl;
        if (pos_y  > init_posy) {
            pos_y = init_posy;
            in_air = false;
            // std::cout << "On Ground\n";
        }
    }
}

void Dinosaur::render(SDL_Renderer *sdl_renderer, SDL_Rect &block) {
    // Render Dinosaur
  SDL_Surface* surface = SDL_LoadBMP(dinosaur.image_path.c_str());
  if (!surface)
  {
      std::cout << "Failed to load Dinosaur image: " << SDL_GetError() << std::endl;
  }

  // Create a texture from the surface
  SDL_Texture* m_texture = SDL_CreateTextureFromSurface(sdl_renderer, surface);
  if (!m_texture)
  {
      std::cout << "Failed to create Dinosaur texture: " << SDL_GetError() << std::endl;
  }
  dest.x = dinosaur.pos_x * block.w;
  dest.y = dinosaur.pos_y * block.h - (surface->h/2);
  dest.w = surface->w/2;
  dest.h = surface->h/2;

  SDL_RenderCopy(sdl_renderer, m_texture, NULL, &dest);

  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}