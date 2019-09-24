#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

//Lets make the GameObject Class!
//This will enable textures and charaters to be rendered to the screen
#include "Game.h"   
class GameObject {
	 
public:
	GameObject(const char* texturesheet, int x, int y);
	//Destructor
	~GameObject();
	//Each object has its own update function for its own specific behaviours
	// This occurs when we declare a single GameObject
	void Update();
	void Render();
	  
private:
	//Location where our object will be on screen
	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	//To display, we need SDL_Rectangle
	//The images are displayed on here
	SDL_Rect srcRect, destRect;
};

#endif // !