#include "engine.h"

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
    bool running = true;
    SDL_Event event;

    while(running) {
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                    running = false;
                break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        for(size_t i = 0; i < drawables.size(); i++) {
            drawables[i]->draw(renderer);
        }

        SDL_RenderPresent(renderer);
    }
}

Engine::~Engine() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
