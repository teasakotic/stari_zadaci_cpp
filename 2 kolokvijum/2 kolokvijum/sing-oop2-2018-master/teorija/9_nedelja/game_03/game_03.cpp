#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>

#include "game.h"

using namespace std;

SDL_Window* gWindow;
SDL_Renderer* gRenderer;

Game game;

void init(){
  SDL_Init(SDL_INIT_VIDEO);
  gWindow = SDL_CreateWindow("Programiranje 2 - Singidunum", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
  gRenderer = SDL_CreateRenderer(gWindow, -1, 0);
}

void close() {
	game.free();

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

    init();
		game.loadFromFile( "pacman_1.png", gRenderer);

    int time = 0;

    // main loop
    while (!quit){
        SDL_PollEvent(&event);
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
        game.eventHandling(event);
        game.tick(time);
        
        // clear window
        SDL_SetRenderDrawColor(gRenderer, 10, 10, 10, 255);
        SDL_RenderClear(gRenderer);

        game.render(gRenderer);
        time++;
        // render window
        SDL_RenderPresent(gRenderer);
        SDL_Delay(10);
    }

    // cleanup SDL
    close();

    return 0;
}
