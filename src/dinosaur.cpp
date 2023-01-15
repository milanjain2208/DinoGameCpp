#include<dinosaur.h>
void Dinosaur::jump() {
    pos_y -= jump_height;
}
void Dinosaur::update() {
    if (init_jump) {
        Dinosaur::jump();
        init_jump = false;
    }
}