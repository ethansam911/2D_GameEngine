#include "TextureManager.h"
//Now implement LoadTexture function
    
//This is a simple texture loader
SDL_Texture* TextureManager::LoadTexture(const char* texture, SDL_Renderer* ren)   
{
	SDL_Surface* tempSurface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tempSurface);

	//free the surface
	SDL_FreeSurface(tempSurface);   

	return tex;
}