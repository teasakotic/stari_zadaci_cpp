#include "ReversedSprite.h"


ReveresedSprite::ReveresedSprite(SpriteSheet *sheet, int width, int height)
    : Sprite(sheet, width, height){}


void ReveresedSprite::draw(SDL_Renderer *renderer){
    if(state&LEFT) {
        sheet->drawFrame("walk_right", currentFrame, spriteRect, renderer);
    } else if(state&RIGHT) {
        sheet->drawFrame("walk_left", currentFrame, spriteRect, renderer);
    } else if(state&UP) {
        sheet->drawFrame("walk_down", currentFrame, spriteRect, renderer);
    } else if(state&DOWN) {
        sheet->drawFrame("walk_up", currentFrame, spriteRect, renderer);
    } else if(state == STOP) {
        sheet->drawFrame("walk_up", 0, spriteRect, renderer);
    }

    frameCounter++;
    if(frameCounter%frameSkip == 0) {
        currentFrame++;
        if(currentFrame >= 9) {
            currentFrame = 0;
        }
        frameCounter = 0;
    }
}

void ReveresedSprite::move(int dx, int dy) {
    spriteRect->x -= dx;
    spriteRect->y -= dy;
}

void ReveresedSprite::move() {
    if(state != 0) {
        if(state & 1) {
            move(1, 0);
        }
        if(state & 2) {
            move(-1, 0);
        }
        if(state & 4) {
            move(0, 1);
        }
        if(state & 8) {
            move(0, -1);
        }
    }
}
