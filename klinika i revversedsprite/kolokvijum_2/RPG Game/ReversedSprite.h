#ifndef REVERSED_SPRITE_H
#define REVERSED_SPRITE_H

#include "sprite.h"

class ReveresedSprite : public Sprite {
    
    public:
        ReveresedSprite(SpriteSheet *sheet, int width = 64, int height = 64);
        virtual void draw(SDL_Renderer *renderer);
        virtual void move();
        virtual void move(int dx, int dy);
};


#endif // REVERSED_SPRITE_H