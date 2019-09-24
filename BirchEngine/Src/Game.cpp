#include "Game.h"
//Remember to include texture manager
#include "TextureManager.h"
//include GameObject because we made a class for the object
#include "GameObject.h"
//We want to be able to use our tilemaps
#include "Map.h"

   
/*       
	We no longer need these because we made the GameObject class
	//Create a texture manager class that'll help us to load images
	SDL_Texture* playerTex;
	//Create our rectangles
	SDL_Rect srcR, destR;
*/

GameObject* player;
GameObject* enemy;
Map* map;

//Initialize to nullptr because we haven't initialized SDL yet
SDL_Renderer* Game::renderer = nullptr;

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
			//Draws a white background
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}

		isRunning = true;
	}
	//Tilemaps created YES! 8/8/2019
	player = new GameObject("assets/player.png", 0, 0);
	enemy = new GameObject("assets/enemy.png", 80, 80);
	//Create a new map (aka our pixels)
	map = new Map();
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
	enemy->Update();
	//Potentially use an XML file or a txt file to load in a custom map

}

void Game::render()
{	//Clear the current renderer
	SDL_RenderClear(renderer);
	map->DrawMap();

	//srcrect rectangle part of rectangle you want to draw
	//First NULL will use entire image, second NULL arg will draw to whole frame
	player->Render();
	enemy->Render();
	SDL_RenderPresent(renderer);
}

void Game::clean() 
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}