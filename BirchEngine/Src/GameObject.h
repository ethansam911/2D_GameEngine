#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H


//Lets make the GameObject Class!
#include "Game.h"   
class GameObject {

public:
	GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y);
	~GameObject();
	//Each object has its own update function for its own specific behaviours
	void Update();
	void Render();

private:
	//Location where our object will be
	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	//To display, we need SDL_Rectangle
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;
};

#endif // !