#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <map>
using namespace std;

#include "draw.h"


Line::Line(int x1, int y1, int x2, int y2){
	a.x = x1;
	a.y = y1;
	b.x = x2;
	b.y = y2;
}

Rectangle::Rectangle(int x1, int y1, int x2, int y2){
	a.x = x1;
	a.y = y1;
	b.x = x2;
	b.y = y2;
}



void Button::eventHandling(SDL_Event event){
	int x, y;
	switch (event.type){
		case SDL_MOUSEBUTTONUP:
			x = event.button.x;
			y = event.button.y;
			break;
		case SDL_MOUSEMOTION:
			x = event.motion.x;
			y = event.motion.y;	
			if(x>=rect.x && x<=rect.x+rect.w && y>=rect.y && y<=rect.y+rect.h){
				hover = true;
			}else{
				hover = false;
			}
			break;
	}
}

void Button::render(SDL_Renderer* gRenderer){
	if(hover)
		SDL_SetRenderDrawColor(gRenderer, 0, 210, 0, 255);
	else
		SDL_SetRenderDrawColor(gRenderer, 100, 0, 0, 255);

	SDL_RenderFillRect(gRenderer, &rect);

	SDL_SetRenderDrawColor(gRenderer, 220, 220, 220, 255);
	SDL_RenderDrawRect(gRenderer, &rect);
};

Canvas::Canvas(){
	Button *button = new Button();
	button->rect.x = 200;
	button->rect.y = 200;
	button->rect.w = 80;
	button->rect.h = 30;
	buttons.push_back(button);
	
	button = new Button();
	button->rect.x = 20;
	button->rect.y = 200;
	button->rect.w = 80;
	button->rect.h = 30;
	buttons.push_back(button);

	// Rectangle rect = Rectangle(400, 50, 480, 200);
	// rect.R = 0;
	// rect.G = 200;
	// rect.B = 0;
	// oblici.push_back(&rect);

	// Rectangle rect1 = Rectangle(200, 50, 280, 200);
	// rect1.R = 0;
	// rect1.G = 0;
	// rect1.B = 200;
	// oblici.push_back(&rect1);

}

bool Canvas::loadFromFile(string path)
{
	// // ucitati datoteku i napuniti niz
	ifstream myfile(path);
	string linija;
	while (getline(myfile, linija))
	{
  		istringstream iss(linija);
  		int x1, y1, x2, y2;
  		if (!(iss >> x1 >> y1>>x2>>y2)) { break; } // error
		oblici.push_back(new Line(x1, y1, x2, y2));
	}
	myfile.close();

	return true;
}

void Canvas::render(SDL_Renderer* gRenderer) {
	for(Shape *obj: oblici){
		obj->render(gRenderer);
	}

	// for(Line linija: linije)
	// 	linija.render(gRenderer);
	for(Button *button: buttons){
		button->render(gRenderer);
	}
	// for(Rectangle rect: pravougaonici){
	// 	rect.render(gRenderer);
	// }
	if(state==1){
      	SDL_SetRenderDrawColor(gRenderer, 100, 100, 100, 255);
		//SDL_RenderDrawLine(gRenderer, pre.x, pre.y, sad.x, sad.y);

		SDL_Rect rect;
		rect.x = pre.x;
		rect.y = pre.y;
		rect.w = sad.x - pre.x;
		rect.h = sad.y - pre.y;
		SDL_RenderFillRect(gRenderer, &rect);


	}
}

void Canvas::eventHandling(SDL_Event event){
	ofstream myfile;
	switch (event.type){
		case SDL_KEYDOWN: //SDL_KEYUP:
			switch( event.key.keysym.sym ){
					case SDLK_LEFT:
							break;
					case SDLK_RIGHT:
							break;
					case SDLK_p:
							break;
					default:
						cout<<event.key.keysym.sym<<"\n";
						break;
			}
          // if(event_listeners.count(event.key.keysym.sym)){
          //   event_listeners[event.key.keysym.sym]->execute();
          // }
				break;
		case SDL_MOUSEBUTTONUP:
			switch(state){
				case 0:
					state = 1;
					break;
				case 1:
					//linije.push_back(Line(pre.x, pre.y, event.button.x, event.button.y));
					Rectangle *rect = new Rectangle(pre.x, pre.y, event.button.x, event.button.y);
					rect->R = 100;
					rect->G = 200;
					rect->B = 0;
					oblici.push_back(rect);

					myfile.open("in.txt", std::ios_base::app);
					myfile << pre.x << " "<< pre.y <<" "<< event.button.x<<" "<<event.button.y<<"\n";
					myfile.close();
					state = 0;
					break;
			}
			pre.x = event.button.x;
			pre.y = event.button.y;
			break;
		case SDL_MOUSEMOTION:
			sad.x = event.motion.x;
			sad.y = event.motion.y;			
			break;
	}
	for(Button *button: buttons){
		button->eventHandling(event);
	}
}

