#ifndef  TEXTURE_MANAGER_H
#define  TEXTURE_MANAGER_H
#include "Game.h"

//We want this texture manager to return an SDL texture

class TextureManager {
public:
	/*
		class function rather than member function
		Don't need to instatntiate an object in each instance 
		that we want to call this function
	*/
	//Return an SDL_Texture pointer
	static SDL_Texture* LoadTexture(const char* filename, SDL_Renderer* ren);
};
#endif