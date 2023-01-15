#include<dinosaur.h>
void Dinosaur::jump() {
    pos_y -= jump_height;
}
void Dinosaur::update() {
    if (initiate_jump) {
        Dinosaur::jump();
        initiate_jump = false;
    }
}