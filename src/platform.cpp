#include<platform.h>
void Platform::update() {
    pos_x = pos_x - (width/80) ;
    if ( pos_x <= -width) {
        pos_x = width;
    }
}