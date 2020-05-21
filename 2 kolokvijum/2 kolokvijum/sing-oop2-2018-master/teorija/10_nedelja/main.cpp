// --------------------   standardni deo koji koristimo za SDL -----------
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
// --------------------   standardni deo koji koristimo za SDL -----------

#include "draw.h"

using namespace std;

SDL_Window* gWindow;
SDL_Renderer* gRenderer;
TTF_Font* font;


Canvas canvas;

void init(){
  SDL_Init(SDL_INIT_VIDEO);
  
  gWindow = SDL_CreateWindow("Programiranje 2 - Singidunum", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
  gRenderer = SDL_CreateRenderer(gWindow, -1, 0);
  font = TTF_OpenFont("lazy.ttf", 24);
}

void close() {

	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	IMG_Quit();
	SDL_Quit();
}


int main(int argc, char ** argv) {
    bool quit = false;
    SDL_Event event;
    int t = 0;

    init();
	canvas.loadFromFile("in.txt");

    // main loop
    while (!quit){
        // SDL_PollEvent(&event);
        while( SDL_PollEvent( &event ) ){
            // event handling
            switch (event.type){
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYDOWN: //SDL_KEYUP:
                    switch( event.key.keysym.sym ){
                        case SDLK_ESCAPE:
                            quit = true;
                            break;
                        default:
                            break;
                    }
                    break;
            }
            canvas.eventHandling(event);
        }

        // clear window
        SDL_SetRenderDrawColor(gRenderer, 210, 0, 0, 255);
        SDL_RenderClear(gRenderer);

        canvas.render(gRenderer);
        // render window
        SDL_RenderPresent(gRenderer);
        SDL_Delay(10);
        stringstream title;
        title << "Vreme: "<<t;
        SDL_SetWindowTitle(gWindow, title.str().c_str());
        t+=1;
    }

    // cleanup SDL
    close();

    return 0;
}
