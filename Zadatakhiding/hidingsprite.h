#ifndef HIDINGSPRITE_H_INCLUDED
#define HIDINGSPRITE_H_INCLUDED

class HidingSprite : public Sprite { ///nova klasa

public:
    HidingSprite(SpriteSheet* ss) : Sprite(ss) {}
    void move() {
        if(state != 0 && state <= 16) { /// dodat uslov da mora da bude manje od 16, jer ako je 16 onda smo u HIDING state-u pa ne mozemo da se pomeramo
            if(state & 1) {
                Sprite::move(-1, 0);
            }
            if(state & 2) {
                Sprite::move(1, 0);
            }
            if(state & 4) {
                Sprite::move(0, -1);
            }
            if(state & 8) {
                Sprite::move(0, 1);
            }
        }
    }

    void draw(SDL_Renderer *renderer) {
        if (state&HIDING){
            ///ne radi nista jer ne treba da se iscrta
        } else if(state&LEFT) {
            sheet->drawFrame("walk_left", currentFrame, spriteRect, renderer);
        } else if(state&RIGHT) {
            sheet->drawFrame("walk_right", currentFrame, spriteRect, renderer);
        } else if(state&UP) {
            sheet->drawFrame("walk_up", currentFrame, spriteRect, renderer);
        } else if(state&DOWN) {
            sheet->drawFrame("walk_down", currentFrame, spriteRect, renderer);
        } else if(state == STOP) {
            sheet->drawFrame("walk_down", 0, spriteRect, renderer);
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

    void setState(short int state){
        if (this->state == HIDING && state == 0){
            this->state = state;
        }
    }
};


#endif // HIDINGSPRITE_H_INCLUDED
