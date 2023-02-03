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