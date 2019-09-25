#ifndef  TEXTURE_MANAGER_H
#define  TEXTURE_MANAGER_H
#include "Game.h"
//Simple Direct Layerupdate
//We want this texture manager to return an SDL texture
class TextureManager 
{
public:
	/*  
		class function rather than member function
		Don't need to instatntiate an object in each instance 
		that we want to call this function
	*/
	//Return an SDL_Texture pointer
	// Filename is for the desired texture, renderer needed as well
	static SDL_Texture* LoadTexture(const char* filename);
	static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
};
#endif