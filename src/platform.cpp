#include<platform.h>
void Platform::update() {
    pos_x = pos_x - (0.1 * width) ;
    if ( pos_x <= -width) {
        pos_x = width;
    }
}