#include "sprite.h"

Sprite::Sprite(int frameWidth, int frameHeight, string spriteSheetPath, SDL_Renderer *renderer) : Drawable(), Movable() {
    state = Sprite::STOP;
    currentFrame = 0;
    frameCounter = 0;
    frameSkip = 1;

    frameRect = new SDL_Rect();
    frameRect->x = 0;
    frameRect->y = 0;
    frameRect->w = frameWidth;
    frameRect->h = frameHeight;

    spriteRect = new SDL_Rect();
    spriteRect->x = 0;
    spriteRect->y = 0;
    spriteRect->w = frameWidth;
    spriteRect->h = frameHeight;

    SDL_Surface *surface = IMG_Load(spriteSheetPath.c_str());
    animationFrameCount = surface->w/frameWidth;
    spriteTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
}

int Sprite::getFrameSkip() {
    return frameSkip;
}

void Sprite::setFrameSkip(int frameSkip) {
    if(frameSkip < 0) {
        frameSkip = 0;
    }

    this->frameSkip = frameSkip+1;
}

short int Sprite::getState() {
    return state;
}

void Sprite::setState(short int state) {
    this->state = state;
}

void Sprite::draw(SDL_Renderer *renderer) {
    frameRect->x = currentFrame*frameRect->w;
    SDL_RenderCopy(renderer, spriteTexture, frameRect, spriteRect);
    frameCounter++;
    if(frameCounter%frameSkip == 0) {
        currentFrame++;
        if(currentFrame >= animationFrameCount) {
            currentFrame = 0;
        }
        frameCounter = 0;
    }
}

void Sprite::move(int dx, int dy) {
    spriteRect->x += dx;
    spriteRect->y += dy;
}

void Sprite::move() {
    if(state != 0) {
        if(state & 1) {
            move(-1, 0);
        }
        if(state & 2) {
            move(1, 0);
        }
        if(state & 4) {
            move(0, -1);
        }
        if(state & 8) {
            move(0, 1);
        }
    }
}
