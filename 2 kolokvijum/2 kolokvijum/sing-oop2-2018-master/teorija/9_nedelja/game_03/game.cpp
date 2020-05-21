#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <map>
using namespace std;

#include "game.h"


Sprite::Sprite(){
    x = 20;
    y = 20;

    w = 14;
    h = 14;

    sy = 125;
    for(int i=0; i<8; i++){
      boxes[i].w = w;
      boxes[i].h = h;
      boxes[i].x = 3+i*17;
      boxes[i].y = sy;
    }
    right();
}

Game::Game()
{
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
	// Sprite duh;
	// duhovi.push_back(duh);
}

Game::~Game()
{
	free();
}

bool Game::loadFromFile( std::string path, SDL_Renderer* gRenderer )
{
	free();
	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

    newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		else
		{
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}
		SDL_FreeSurface( loadedSurface );
	}

	mTexture = newTexture;
	pozadina.textura = mTexture;
	duhA.textura = mTexture;
  duhB.textura = mTexture;
	duhC.textura = mTexture;
  duhA.y = 157;//157 228
	duhB.x = 157;
  duhB.y = 228;

	duhC.y = 250;
	duhC.x = 150;

	// ucitati datoteku i napuniti niz
	ifstream myfile("hodnici.txt");
	string linija;
	while (getline(myfile, linija))
	{
    std::istringstream iss(linija);
		cout<<linija<<"\n";
    int a, b;
    if (!(iss >> a >> b)) { break; } // error
    // // process pair (a,b)
		tackice.push_back(Tackica(a,b));
	}
	myfile.close();

  SpriteEventHandler* duhBLevo = new SpriteEventHandler();
  duhBLevo->code = 97;
  duhBLevo->obj = &duhB;
  duhBLevo->function = &Sprite::left;

  /*http://en.qi-hardware.com/wiki/Key_codes*/
  event_listeners[97] = duhBLevo;
  event_listeners[115] = new SpriteEventHandler(115, &duhB, &Sprite::right); // s

  event_listeners[119] = new SpriteEventHandler(119, &duhB, &Sprite::up); // w
  event_listeners[122] = new SpriteEventHandler(122, &duhB, &Sprite::down); // z

  event_listeners[114] = new SpriteEventHandler(114, &duhC, &Sprite::up); // r
	event_listeners[102] = new SpriteEventHandler(102, &duhC, &Sprite::down); // f


	return mTexture != NULL;
}

void Game::free()
{
	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void Game::render(SDL_Renderer* gRenderer) {
	pozadina.render(gRenderer);
	duhA.render(gRenderer);
  duhB.render(gRenderer);
	duhC.render(gRenderer);
	for(Sprite duh: duhovi)
		duh.render(gRenderer);
	for(Tackica tackica: tackice)
		tackica.render(gRenderer);
}

void Game::eventHandling(SDL_Event event){
	ofstream myfile;
	ofstream hodnici;
	duhB.dx = 0;
	duhB.dy = 0;
	switch (event.type){
			case SDL_KEYDOWN: //SDL_KEYUP:
					switch( event.key.keysym.sym ){
							case SDLK_LEFT:
                  duhA.left();
									break;
							case SDLK_RIGHT:
                  duhA.right();
									break;
							case SDLK_p:
									hodnici.open("hodnici.txt", std::ios_base::app);
									hodnici << duhB.x<<" "<<duhB.y<<"\n";
									hodnici.close();
									tackice.push_back(Tackica(duhB.x,duhB.y));

                  // cout<<duhB.x<<", "<<duhB.y;
									break;
              // case 97: // a
              //     duhB.left();
							// 		break;
							// case 115: // s
              //     duhB.right();
							// 		break;
							default:
                cout<<event.key.keysym.sym<<"\n";
								break;
					}
          if(event_listeners.count(event.key.keysym.sym)){
            event_listeners[event.key.keysym.sym]->execute();
          }
					break;
			case SDL_MOUSEBUTTONUP:
					myfile.open("out.txt", std::ios_base::app);
					myfile << event.button.x<<" "<<event.button.y<<"\n";
					myfile.close();
					Sprite duh;
					duh.textura = mTexture;
					duh.x = event.button.x;
					duh.y = event.button.y;
					duh.dx = 0;
					duh.dy = 0;
					duhovi.push_back(duh);
					break;
			// case SDL_MOUSEMOTION:
			// 		int mouseX = event.motion.x;
			// 		int mouseY = event.motion.y;			
			// 		std::stringstream ss;
			// 		ss << "X: " << mouseX << " Y: " << mouseY;
			// 		// SDL_SetWindowTitle(window, ss.str().c_str());
			//  		break;
		}
}

void Game::tick(int time){
  duhA.tick(time);
  duhB.tick(time);
	duhC.tick(time);
}
