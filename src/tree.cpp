#include<tree.h>
void Tree::update() {
    pos_x = random_x(engine);
}

void Tree::render(SDL_Renderer *sdl_renderer, SDL_Rect &block) {
    // Render tree
    SDL_Surface* surface = SDL_LoadBMP(image_path.c_str());
    if (!surface)
    {
        std::cout << "Failed to load image: " << SDL_GetError() << std::endl;
    }

    // Create a texture from the surface
    SDL_Texture* texture = SDL_CreateTextureFromSurface(sdl_renderer, surface);
    if (!texture)
    {
        std::cout << "Failed to create texture: " << SDL_GetError() << std::endl;
    }
    dest.x = pos_x * block.w;
    dest.y = pos_y * block.h - (surface->h);
    dest.w = surface->w;
    dest.h = surface->h;

    SDL_RenderCopy(sdl_renderer, texture, NULL, &dest);
}