#include<platform.h>
void Platform::update() {
    pos_x = pos_x - (width/40) ;
    tree.pos_x = tree.pos_x - (width/40) ;
    if ( pos_x <= -width) {
        pos_x = width;
        tree.update();
    }
}

void Platform::render(SDL_Renderer *sdl_renderer, SDL_Rect &block) {
    SDL_Surface* surface = SDL_LoadBMP(image_path.c_str());
    if (!surface)
    {
        std::cout << "Failed to load platform image: " << SDL_GetError() << std::endl;
    }

    // Create a texture from the surface
    SDL_Texture* texture = SDL_CreateTextureFromSurface(sdl_renderer, surface);
    if (!texture)
    {
        std::cout << "Failed to create platform texture: " << SDL_GetError() << std::endl;
    }
    dest.x = pos_x * block.w;
    dest.y = pos_y * block.h;
    dest.w = width;
    dest.h = surface->h;
    SDL_RenderCopy(sdl_renderer, texture, NULL, &dest);

    tree.render(sdl_renderer,block);
}