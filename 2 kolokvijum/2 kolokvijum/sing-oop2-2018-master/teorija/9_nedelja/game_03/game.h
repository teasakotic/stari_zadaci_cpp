#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <string>
#include <map>
#include <vector>
using namespace std;


class Sprite{
	public:
		Sprite();
		// ~Sprite();

		SDL_Texture* textura;
    int dx, dy;
		int x,y,w,h;
    int sx, sy;
		SDL_Rect boxes[8];

		virtual void render(SDL_Renderer* gRenderer){
			SDL_Rect clip = { sx, sy, w, h }; // ovo su koordinate na slici
			SDL_Rect renderQuad = { x, y, 2*w, 2*h }; // ovo su koordinate na ekranu
			SDL_RenderCopy( gRenderer, textura, &clip, &renderQuad );
		};

    virtual void tick(int time){
      x = x + dx;
      y = y + dy;
    };

    virtual void left(){
      dx = -7;
      dy = 0;
      sx = boxes[3].x;
    }

    virtual void right(){
      dx = 7;
      dy = 0;
      sx = boxes[0].x;
    }

    virtual void up(){
      dx = 0;
      dy = -7;
      sx = boxes[4].x;
    }

    virtual void down(){
      dx = 0;
      dy = 7;
      sx = boxes[6].x;
    }


};

/* Definicija novog tipa:
      pokazivac na funkciju iz klase Sprite
*/
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

class Tackica:public Sprite{
  public:
    Tackica(int ax, int ay){
      x = ax;
      y = ay;
    }
		void render(SDL_Renderer* gRenderer){
        SDL_SetRenderDrawColor(gRenderer, 210, 210, 210, 255);
        SDL_RenderDrawLine(gRenderer, x, y, x+5, y+5);
        SDL_RenderDrawLine(gRenderer, x, y, x-5, y+5);
    }
};

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
    Sprite duhC;
    vector<Sprite> duhovi;
    vector<Tackica> tackice;
 		SDL_Texture* mTexture;

		int mWidth;
		int mHeight;
};
