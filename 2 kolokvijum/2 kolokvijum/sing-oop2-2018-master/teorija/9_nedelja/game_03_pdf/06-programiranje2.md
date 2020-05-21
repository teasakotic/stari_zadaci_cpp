---
author:
- dr Đorđe Obradović
institute: Singidunumasd ada
title: Programiranje 2
subtitle: Pokazivaci i funkcije
university: Singidunum - Centar Novi Sad
fontsize: 17pt
# toc: true
date: Singidunum  - Centar Novi Sad
...

# Igra 03 - Pacman

## Uvod

U ovom primeru biće prikazana implementacija kretanja dva igrača.

Novost u odnosu na prethodne primere je poboljšan mehanizam za upravljanje događajima i
bolja struktuiranost elemenata projekta.

## Osnovni elementi

\begin{figure}
\includegraphics[height=0.7\textheight,keepaspectratio]{images/pacman_1.png}
\end{figure}

## Mapa elemenata - pacman

\begin{figure}
\includegraphics[height=0.7\textheight,keepaspectratio]{images/pacman01.png}
\end{figure}

w:14, h:14 | y: 90 |  x: 3, 19, 33, 47, 61, 75, 92, 109, 126

## Mapa elemenata - crveni duh

\begin{figure}
\includegraphics[height=0.7\textheight,keepaspectratio]{images/pacman01.png}
\end{figure}

w:14, h:14 | y: 125 |  x: 3, 20, 37, 54, 71, 88, 105, 122

## Mapa elemenata - pozadina

\begin{figure}
\includegraphics[height=0.7\textheight,keepaspectratio]{images/pacman02.png}
\end{figure}

w:165, h:214 | y: 2 |  x: 201


# Zadatak

## Zadatak

Implementirati klase

- Sprite,
- Pozadina i
- Game

i povezati sa main funkcijom u jednu celinu.

## klasa Sprite

Klasa Sprite koristi se za upravljanje jednom figurom.


## klasa Pozadina

Klasa Pozadina koristi se za upravljanje pozadinom i prikazivanjem rezultata.

## Klasa Game

U ovoj klasi se obrađuju svi događaji, raspoređuje upravljanje kretanjem i vrši prikazivanje svih komponenti igre.

# Implementacija


## Klasa Sprite

\tiny

```{.cpp .numberLines numbers="left" startFrom="0"}
  class Sprite{
  	public:
      Sprite();

      SDL_Texture* textura;
      int dx, dy;
      int x,y,w,h;
      int sx, sy;
      SDL_Rect boxes[8];

      virtual void render(SDL_Renderer* gRenderer);
      virtual void tick(int time);
      virtual void left();
      virtual void right();
      virtual void up();
      virtual void down();
  };
```

## Klasa Pozadina

\tiny

```{.cpp .numberLines numbers="left" startFrom="0"}
class Pozadina:public Sprite{
	public:
		Pozadina(){
			x = 640/2-165;
			y = 480/2-214;
			sx = 201;
			sy = 2;
			w = 165;
			h = 214;
		}

		void render(SDL_Renderer* gRenderer){
			SDL_Rect clip = { sx, sy, w, h }; // ovo su koordinate na slici
			SDL_Rect renderQuad = { x, y, 2*w, 2*h }; // ovo su koordinate na ekranu
			SDL_RenderCopy( gRenderer, textura, &clip, &renderQuad );
		}
};
```

## Klasa Game

\tiny

```{.cpp .numberLines numbers="left" startFrom="0"}
class Game {
  	public:
        Game();
        ~Game();

        bool loadFromFile(string, SDL_Renderer*);
        void free();
        void eventHandling(SDL_Event);
        void tick(int);
        void render(SDL_Renderer* gRenderer);
        map<int, SpriteEventHandler*> event_listeners;

  	private:
        Pozadina pozadina;
        Sprite duhA;
        Sprite duhB;
        SDL_Texture* mTexture;
        int mWidth;
        int mHeight;
};

```

## Event handling

\tiny

```{.cpp .numberLines numbers="left" startFrom="0"}
void Game::eventHandling(SDL_Event event){
	switch (event.type){
			case SDL_KEYDOWN: //SDL_KEYUP:
					switch( event.key.keysym.sym ){
							case SDLK_LEFT:
                  duhA.left();
									break;
							case SDLK_RIGHT:
                  duhA.right();
									break;
							default:
								break;
					}
					break;
		}
}
```

## Event handling - unapređen

Formirati mapu u kojoj će se nalaziti funkcije koje će se pozivati kao reakcija na događaj.


## Event handling - unapređen

\tiny

```{.cpp .numberLines numbers="left" startFrom="0"}
void Game::eventHandling(SDL_Event event){
  switch (event.type){
    case SDL_KEYDOWN: //SDL_KEYUP:
      switch( event.key.keysym.sym ){
        case SDLK_LEFT:
          duhA.left();
          break;
        case SDLK_RIGHT:
          duhA.right();
          break;
        default:
          break;
      }
      if(event_listeners.count(event.key.keysym.sym)){
        event_listeners[event.key.keysym.sym]->execute();
      }          
      break;
  }
}
```

## Event handling - unapređen

\tiny

```{.cpp .numberLines numbers="left" startFrom="0"}
typedef void (Sprite::*SpriteFunction)();

class SpriteEventHandler{
  public:
    int code;
    Sprite* obj;
    SpriteFunction function;

    SpriteEventHandler(){};
    SpriteEventHandler(int aCode, Sprite* aObj, SpriteFunction aFunction){
      code = aCode;
      obj = aObj;
      function = aFunction;
    };

    void execute(){
      (obj->*function)();
    };
};
```

## Event handling - unapređen

\tiny

```{.cpp .numberLines numbers="left" startFrom="0"}

event_listeners[115] = new SpriteEventHandler(115, &duhB, &Sprite::right); // s
event_listeners[119] = new SpriteEventHandler(119, &duhB, &Sprite::up); // w
event_listeners[122] = new SpriteEventHandler(122, &duhB, &Sprite::down); // z

```

# Literatura


## Literatura

- https://www.libsdl.org/
- https://en.wikipedia.org/wiki/Simple_DirectMedia_Layer
- http://lazyfoo.net/tutorials/SDL/


# Domaći

## Zadaci za vežbu

1. Napraviti mapu slika za narandžaste duhove.
2. Implementirati funkcije za proveru mogućeg kretanja duhova i igrača.
3. Nacrtati tačkice za bodove.
4. Ispisati labelu za rezultat i ispod  nje svoje ime.
5. Omogućiti duhovima kretanje.

## Pakmen

\begin{figure}
\includegraphics[height=0.7\textheight,keepaspectratio]{images/pacman_1.png}
\end{figure}
