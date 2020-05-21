#include "sprite.h"

Sprite::Sprite(string name, int x, int y) {
    this->x = x;
    this->y = y;
    this->name = name;
}

void Sprite::setX(int x) {
    this->x = x;
}

void Sprite::setY(int y) {
    this->y = y;
}

void Sprite::setName(string name) {
    this->name = name;
}

