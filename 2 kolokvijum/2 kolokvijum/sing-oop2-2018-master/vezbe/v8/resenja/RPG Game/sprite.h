#ifndef SPRITE_H_INCLUDED
#define SPRITE_H_INCLUDED

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "drawable.h"
#include "movable.h"

using namespace std;

class Sprite : public Drawable, public Movable {
private:
    short int state;
    SDL_Texture *spriteTexture;
    SDL_Rect *spriteRect;
    SDL_Rect *frameRect;
    int currentFrame;
    int animationFrameCount;
    int frameCounter;
    int frameSkip;
public:
    Sprite(int frameWidth, int frameHeight, string spriteSheetPath, SDL_Renderer *renderer);
    int getFrameSkip();
    void setFrameSkip(int frameSkip);
    short int getState();
    void setState(short int state);
    virtual void draw(SDL_Renderer *renderer);
    virtual void move();
    virtual void move(int dx, int dy);

};

#endif // SPRITE_H_INCLUDED
