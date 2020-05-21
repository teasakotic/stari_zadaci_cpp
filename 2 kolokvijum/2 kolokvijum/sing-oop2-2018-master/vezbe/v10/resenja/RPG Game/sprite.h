#ifndef SPRITE_H_INCLUDED
#define SPRITE_H_INCLUDED

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "drawable.h"
#include "movable.h"

#include "spritesheet.h"

using namespace std;

class Sprite : public Drawable, public Movable {
public:
    enum State:short int {STOP=0, LEFT=1, RIGHT=2, UP=4, DOWN=8,
                     LEFT_UP=LEFT|UP, LEFT_DOWN=LEFT|DOWN,
                     RIGHT_UP=RIGHT|UP, RIGHT_DOWN=RIGHT|DOWN};
private:
    short int state;
    SpriteSheet *sheet;
    SDL_Rect *spriteRect;
    int currentFrame;
    int frameCounter;
    int frameSkip;
public:
    Sprite(SpriteSheet *sheet, int width=64, int height=64);
    int getFrameSkip();
    void setFrameSkip(int frameSkip);
    short int getState();
    void setState(short int state);
    virtual void draw(SDL_Renderer *renderer);
    virtual void move();
    virtual void move(int dx, int dy);

};

#endif // SPRITE_H_INCLUDED
