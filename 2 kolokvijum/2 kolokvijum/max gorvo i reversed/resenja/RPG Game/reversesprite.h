#ifndef REVERSESPRITE_H_INCLUDED
#define REVERSESPRITE_H_INCLUDED
#include "sprite.h"

class Reversesprite:public Sprite{
public:
    float gorivo;
    float maxgorivo;
    Reversesprite(SpriteSheet *sheet, int width=64, int height=64, float maxgorivo=1000):Sprite(sheet, width, height){
        this->maxgorivo= maxgorivo;
        this->gorivo = maxgorivo;
    };

    void move(int dx, int dy) {
    spriteRect->x += dx;
    spriteRect->y += dy;
}

void move() {
    if(state != 0 && this->gorivo>0) {
        if(state & 2) {
            move(-1, 0);
        }
        if(state & 1) {
            move(1, 0);
        }
        if(state & 8) {
            move(0, -1);
        }
        if(state & 4) {
            move(0, 1);
        }
    }
    else{
        setState(0);
    }
}
};

#endif // REVERSESPRITE_H_INCLUDED
