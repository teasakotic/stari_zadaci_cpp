#ifndef RUNNINGSPRITE_H_INCLUDED
#define RUNNINGSPRITE_H_INCLUDED

#include "sprite.h"

class RunningSprite: public Sprite{
public:
    int multiplier = 1;
    RunningSprite(SpriteSheet* sheet,int width = 64, int height=64):Sprite(sheet,width,height){};

    void move(int dx, int dy) {
    spriteRect->x += dx;
    spriteRect->y += dy;
}

    void move() {
    if(multiplier <=10){
        multiplier++;
    }

    if(state != 0) {
        if(state & 1) {
            move(-multiplier, 0);
        }
        if(state & 2) {
            move(multiplier, 0);
        }
        if(state & 4) {
            move(0, -multiplier);
        }
        if(state & 8) {
            move(0, multiplier);
        }
    }
    else{
        multiplier=1;
    }
}

};



#endif // RUNNINGSPRITE_H_INCLUDED
