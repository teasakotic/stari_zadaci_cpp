#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include <string>
#include <map>
#include <vector>
using namespace std;

class Position{
  public:
    int x,y;
};


class Line{
	public:
		Line(int, int, int, int);
		// ~Line();

    Position a;
    Position b;

		virtual void render(SDL_Renderer* gRenderer){
      SDL_SetRenderDrawColor(gRenderer, 210, 210, 210, 255);
			SDL_RenderDrawLine(gRenderer, a.x, a.y, b.x, b.y);
		};

};

class Rectangle{
	public:
		Rectangle(int, int, int, int);
		// ~Line();

    Position a;
    Position b;

    int R;
    int G;
    int B;

		virtual void render(SDL_Renderer* gRenderer){
      SDL_SetRenderDrawColor(gRenderer, R, G, B, 255);
      SDL_Rect rect;
      rect.x = a.x;
      rect.y = a.y;
      rect.w = b.x - a.x;
      rect.h = b.y - a.y;
			SDL_RenderFillRect(gRenderer, &rect);
		};

};




class Button{

  public:
    SDL_Rect rect;
    string text;
    bool hover;

    virtual void eventHandling(SDL_Event);
    //void *onClick(int, int);

		virtual void render(SDL_Renderer* gRenderer);  
};

class Canvas {
	public:
    Canvas();
		void eventHandling(SDL_Event);
		void render(SDL_Renderer* gRenderer);
    bool loadFromFile(string path);

    int state = 0;
    Position pre;
    Position sad;

	private:
    vector<Line> linije;
    vector<Rectangle>  pravougaonici;
    vector<Button*> buttons;
};

