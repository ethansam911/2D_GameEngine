#include "Game.h"
//Remember to include texture manager
#include "TextureManager.h"
//include GameObject because we made a class for the object
#include "GameObject.h"


/*
	We no longer need these because we made the GameObject class
	//Create a texture manager class that'll help us to load images
	SDL_Texture* playerTex;
	//Create our rectangles
	SDL_Rect srcR, destR;
*/

GameObject* player;

Game::Game()
{}
   
Game::~Game()
{}
//Initialize texture in the init() function
void Game::init(const char* title, int width, int height, bool fullscreen)
{
	int flags = 0;
	
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}

		isRunning = true;
	}

	player = new GameObject("assets/player.png", renderer);
}

void Game::handleEvents()
{
	SDL_Event event;

	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT :
		isRunning = false;
		break;
	default:
		break;
	}
}
//Changes made 06/14/2019 will place player on the screen!
void Game::update()
{
	player->Update();
}

void Game::render()
{
	SDL_RenderClear(renderer);
	//srcrect rectangle part of rectangle you want to draw
	//First NULL will use entire image, second NULL arg will draw to whole frame
	player->Render();
	SDL_RenderPresent(renderer);
}

void Game::clean() 
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}