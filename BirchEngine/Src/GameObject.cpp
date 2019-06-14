#include "GameObject.h"
#include "TextureManager.h"
/*
	A major new addition to SDL 2 is the texture rendering API.
	... Textures in SDL have their own data type intuitively called
	a SDL_Texture. When we deal with SDL textures you need an
	SDL_Renderer to render it to the screen
*/

//Constructor
GameObject::GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y)
{
	renderer = ren;
	objTexture = TextureManager::LoadTexture(texturesheet, ren);
	xpos = x;
	ypos = y;
}

void GameObject::Update()
{
	xpos++;
	ypos++;

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.h = srcRect.h*2;
	destRect.w = srcRect.w*2;
}

void GameObject::Render()
{
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}