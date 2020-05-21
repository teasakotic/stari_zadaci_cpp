---
author:
- dr Đorđe Obradović
institute: Singidunumasd ada
title: Programiranje 2
subtitle: Kontruktor, destruktor indirektno adresiranje
university: Singidunum - Centar Novi Sad
fontsize: 17pt
# toc: true
date: Singidunum  - Centar Novi Sad
...

# Igra 02 - Animacija

## Simulacija kretanja

\begin{figure}
\includegraphics[height=0.7\textheight,keepaspectratio]{images/boy.png}
\end{figure}


## Opis i cilj demonstracije

Demonstrirati tehnike potrebne za implementaciju kretanja pomoću SDL biblioteke

# Implementacija


## Biblioteke

\footnotesize

```{.cpp .numberLines numbers="left" startFrom="0"}
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
using namespace std;
```

## Main funkcija

\tiny

```{.cpp .numberLines numbers="left" startFrom="0"}
int main(int argc, char ** argv) {
    bool quit = false;
    SDL_Event event;

    // init SDL ================================================
    init();
    loadMedia();

    // main loop ================================================

    // cleanup SDL ==============================================
    close();
    return 0;
}
```

## Main loop

\footnotesize

```{.cpp .numberLines numbers="left" startFrom="0"}
int dx = 1;
int frame = 0;
int x = 0;

// main loop
while (!quit){
    SDL_Delay(10);
    //------ event handling ----------
    //------ render frame ---------
}
```

## Render frame

\begin{figure}
\includegraphics[height=0.7\textheight,keepaspectratio]{images/boy.png}
\end{figure}


## Render frame

\footnotesize

```{.cpp .numberLines numbers="left" startFrom="0"}
SDL_SetRenderDrawColor(gRenderer, 100, 100, 100, 255);
SDL_RenderClear(gRenderer);

int iClip = frame / 8;
if(dx<0)
  iClip = 8+frame / 8;
SDL_Rect* currentClip = &gSpriteClips[ iClip ];
gSpriteSheetTexture.render(x, 100, currentClip );

++frame;
if( frame / 8 >= WALKING_ANIMATION_FRAMES ){
  frame = 0;
}
SDL_RenderPresent(gRenderer);

```

## Event handling

\tiny

```{.cpp .numberLines numbers="left" startFrom="0"}
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
            case SDLK_ESCAPE:
                quit = true;
                break;
            default:
                break;
        }
        break;
  }
// move objects
x = x + dx;
if(x<0)
  dx = 1;

if(x>640)
  dx = -1;
```

# Igrac

## Klasa - H

\footnotesize

```{.cpp .numberLines numbers="left" startFrom="0"}
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
```

## Igrac - CPP Kontruktor

\footnotesize

```{.cpp .numberLines numbers="left" startFrom="0"}
Igrac::Igrac()
{
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}
```

## Igrac - CPP Destruktor

\footnotesize

```{.cpp .numberLines numbers="left" startFrom="0"}
Igrac::~Igrac()
{
	free();
}
```

## Igrac - CPP loadFromFile

\tiny

```{.cpp .numberLines numbers="left" startFrom="0"}
bool Igrac::loadFromFile( std::string path ){
  free();
  SDL_Texture* newTexture = NULL;
  SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
  SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );
  newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
  mWidth = loadedSurface->w;
  mHeight = loadedSurface->h;
  SDL_FreeSurface( loadedSurface );
  mTexture = newTexture;
  return mTexture != NULL;
}
```

## Globalne funkcije i promenljive

\footnotesize

```{.cpp .numberLines numbers="left" startFrom="0"}
void init(){
  SDL_Init(SDL_INIT_VIDEO);
  gWindow = SDL_CreateWindow("Programiranje 2 - Singidunum",
      SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
  gRenderer = SDL_CreateRenderer(gWindow, -1, 0);

}
```

## Globalne funkcije i promenljive

\footnotesize

```{.cpp .numberLines numbers="left" startFrom="0"}
void loadMedia(){
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
```

# Literatura


## Literatura

- https://www.libsdl.org/
- https://en.wikipedia.org/wiki/Simple_DirectMedia_Layer
- http://lazyfoo.net/tutorials/SDL/

## Korisno Ubuntu

```
sudo apt-get install libsdl2-dev
sudo apt-get install libsdl2-image-2.0-0
sudo apt-get install libsdl2-image-dev
sudo apt-get install libsdl2-image-dbg
sudo apt-get install libsdl2-ttf-dev
```

# Domaći

## Zadaci za vežbu

1. Nacrtati dve horizotalne linije zelenu ispod igrača i plavu iznad
2. Odovjiti delove koda u logicne celine (h, cpp, main)
3. Omoguciti igracu da se zaustavi
4. Implementirati skok igrača (bez animacije)
5. Ubaciti belu loptu koja se nalazi ispred igrača
6. Implementirati kretanje pakmen igrača korišćenjem slike

## Pakmen

\begin{figure}
\includegraphics[height=0.7\textheight,keepaspectratio]{images/pacman_1.png}
\end{figure}
