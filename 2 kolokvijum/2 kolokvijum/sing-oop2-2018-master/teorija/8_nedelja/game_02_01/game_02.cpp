#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
using namespace std;

SDL_Window* gWindow;
SDL_Renderer* gRenderer;

class Igrac {
	public:
		Igrac();
		~Igrac();

		bool loadFromFile(string path );
		void free();
		void render( int x, int y, SDL_Rect* clip = NULL );

	private:
		SDL_Texture* mTexture;

		int mWidth;
		int mHeight;
};

Igrac gSpriteSheetTexture;
const int WALKING_ANIMATION_FRAMES = 8;
SDL_Rect gSpriteClips[ 2*WALKING_ANIMATION_FRAMES ];


Igrac::Igrac()
{
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

Igrac::~Igrac()
{
	free();
}

bool Igrac::loadFromFile( std::string path )
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
	return mTexture != NULL;
}

void Igrac::free()
{
	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void Igrac::render( int x, int y, SDL_Rect* clip ) {
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	if( clip != NULL ){
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	SDL_RenderCopy( gRenderer, mTexture, clip, &renderQuad );
}

void init(){
  SDL_Init(SDL_INIT_VIDEO);
  gWindow = SDL_CreateWindow("Programiranje 2 - Singidunum",
      SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
  gRenderer = SDL_CreateRenderer(gWindow, -1, 0);

}

void loadMedia()
{
	gSpriteSheetTexture.loadFromFile( "boy.png" );
  for(int i=0; i<8; i++){
    gSpriteClips[ i ].x =  i*108;
		gSpriteClips[ i ].y =   0;
		gSpriteClips[ i ].w = 108;
		gSpriteClips[ i ].h = 140;
  }

  for(int i=0; i<8; i++){
    gSpriteClips[ 8+i ].x =  i*108;
		gSpriteClips[ 8+i ].y =   140;
		gSpriteClips[ 8+i ].w = 108;
		gSpriteClips[ 8+i ].h = 140;
  }
}

void close() {
	gSpriteSheetTexture.free();

	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	IMG_Quit();
	SDL_Quit();
}

void debug(string log, TTF_Font* font, SDL_Renderer* renderer){
	SDL_Color white = {255, 255, 255};
	SDL_Surface* sm = TTF_RenderText_Solid(font, log.c_str(), white);
	SDL_Texture* poruka = SDL_CreateTextureFromSurface(renderer, sm);
	SDL_Rect poruka_box; //create a rect
	poruka_box.x = 320;
	poruka_box.y = 20;
	poruka_box.w = sm->w;
	poruka_box.h = sm->h;
	SDL_RenderCopy(renderer, poruka, NULL, &poruka_box);
}

int main(int argc, char ** argv) {
    bool quit = false;
    SDL_Event event;

    init();
    loadMedia();
    int ret = TTF_Init();
    TTF_Font* font = TTF_OpenFont("Roboto-Light.ttf", 16);	

    int dx = 1;
    int frame = 0;
    int x = 0;
	int state = 1;

    // main loop
    while (!quit){
        SDL_Delay(10);
        SDL_PollEvent(&event);
        // event handling
        switch (event.type){
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_KEYDOWN: //SDL_KEYUP:
                switch( event.key.keysym.sym ){
                    case SDLK_LEFT:
                        dx = -1;
                        break;
                    case SDLK_RIGHT:
                        dx = 1;
                        break;
                    case SDLK_SPACE:
                        if(state == 0)
							state = 1;
						else
							state = 0;
                        break;
                    case SDLK_ESCAPE:
                        quit = true;
                        break;
                    default:
                        break;
                }
                break;
          }
        // move objects
		if(state == 1)
        	x = x + dx;
        if(x<0)
          dx = 1;

        if(x>640)
          dx = -1;

        // clear window
        SDL_SetRenderDrawColor(gRenderer, 100, 100, 100, 255);
        SDL_RenderClear(gRenderer);

        int iClip = frame / 8;
        if(dx<0)
          iClip = 8+frame / 8;
        SDL_Rect* currentClip = &gSpriteClips[ iClip ];
        gSpriteSheetTexture.render(x, 100, currentClip );
		stringstream msg;
		msg << "frame: " << frame << " " << iClip;
		string mm = msg.str();
		debug(mm, font, gRenderer);

        // if(state == 1)
		frame++;
		if( frame / 8 >= WALKING_ANIMATION_FRAMES ){
			frame = 0;
		}

        // render window
        SDL_RenderPresent(gRenderer);
    }

    // cleanup SDL
    close();

    return 0;
}
