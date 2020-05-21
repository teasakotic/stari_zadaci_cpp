#include "engine.h"

ostream& operator<<(ostream& out, const Level& l) {
    int rows = l.getLevelMatrix().size();
    int cols = 0;
    if(rows > 0) {
        cols = l.getLevelMatrix()[0].size();
    }
    out << rows << " " << cols << endl;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++) {
            out << l.getLevelMatrix()[i][j] << " ";
        }
        out << endl;
    }

    return out;
}

Engine::Engine(string title) {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void Engine::addTileset(Tileset *tileset, const string &name) {
    tilesets[name] = tileset;
}

void Engine::addTileset(istream &inputStream, const string &name) {
    addTileset(new Tileset(inputStream, renderer), name);
}

void Engine::addTileset(const string &path, const string &name) {
    ifstream tilesetStream(path);
    addTileset(tilesetStream, name);
}

Tileset* Engine::getTileset(const string &name) {
    return tilesets[name];
}

void Engine::addDrawable(Drawable *drawable) {
    drawables.push_back(drawable);
}

void Engine::run() {
    int maxDelay = 1000/frameCap;
    int frameStart = 0;
    int frameEnd = 0;

    bool running = true;
    SDL_Event event;

    cout << (*dynamic_cast<Level*>(drawables[0])) << endl;

    Sprite *sp = new Sprite(64, 64, "resources/creatures/human1_walk2.png", renderer);
    sp->setFrameSkip(4);
    drawables.push_back(sp);
    movables.push_back(sp);

    while(running) {
        frameStart = SDL_GetTicks();
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                    running = false;
                break;
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym) {
                        case SDLK_LEFT:
                            sp->setState(sp->getState()|Sprite::LEFT);
                        break;
                        case SDLK_RIGHT:
                            sp->setState(sp->getState()|Sprite::RIGHT);
                        break;
                        case SDLK_UP:
                            sp->setState(sp->getState()|Sprite::UP);
                        break;
                        case SDLK_DOWN:
                            sp->setState(sp->getState()|Sprite::DOWN);
                        break;
                    }
                break;
                case SDL_KEYUP:
                    switch(event.key.keysym.sym) {
                        case SDLK_LEFT:
                            sp->setState(sp->getState()&~Sprite::LEFT);
                        break;
                        case SDLK_RIGHT:
                            sp->setState(sp->getState()&~Sprite::RIGHT);
                        break;
                        case SDLK_UP:
                            sp->setState(sp->getState()&~Sprite::UP);
                        break;
                        case SDLK_DOWN:
                            sp->setState(sp->getState()&~Sprite::DOWN);
                        break;
                    }
                break;
            }
        }

        for(size_t i = 0; i < movables.size(); i++) {
            movables[i]->move();
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        for(size_t i = 0; i < drawables.size(); i++) {
            drawables[i]->draw(renderer);
        }

        SDL_RenderPresent(renderer);

        frameEnd = SDL_GetTicks();
        if(frameEnd - frameStart < maxDelay) {
            SDL_Delay(maxDelay - (frameEnd - frameStart));
        }
    }
}

Engine::~Engine() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
