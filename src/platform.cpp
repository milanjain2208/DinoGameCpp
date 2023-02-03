#include<platform.h>
void Platform::update() {
    pos_x = pos_x - (width/40) ;
    tree.pos_x = tree.pos_x - (width/40) ;
    if ( pos_x <= -width) {
        pos_x = width;
        tree.update();
    }
}