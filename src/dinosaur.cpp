#include<dinosaur.h>
void Dinosaur::jump() {
    init_jumptime = SDL_GetTicks();
    jump_velocity = -1 * static_cast<int>(0.1*grid_height);
    in_air = true;
}
void Dinosaur::update() {
    if (init_jump) {
        Dinosaur::jump();
        init_jump = false;
    }
    if(in_air) {
        int curr_jumptime = SDL_GetTicks();
        int time_duration = curr_jumptime - init_jumptime;
        pos_y = static_cast<int>(jump_velocity * time_duration + 0.5 * jump_accn * time_duration * time_duration);
        if (pos_y  == init_posy) {
            in_air = false;
        }
    }
}