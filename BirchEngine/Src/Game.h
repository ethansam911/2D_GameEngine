#ifndef GAME_H 
#define GAME_H 

#include "SDL.h"
#include "SDL_image.h"     
#include <iostream>
   
class Game  
{   
public:
	Game();
	~Game();
	void init(const char* title, int width, int height, bool fullscreen);
	void handleEvents();
	void update();    
	bool running(){return isRunning;}
	void render();
	void clean();
	static SDL_Renderer *renderer;

private:
	bool isRunning = false;
	int cnt = 0;
	//SDL_Window is the struct that holds all 
	//info about the Window itself: size, position, 
	//full screen, borders etc. (Below is a pointer to the window itself)
	SDL_Window *window;
};

#endif 