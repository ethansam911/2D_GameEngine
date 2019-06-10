#include "Game.h"
//Create a texture manager class that'll help us to load images
SDL_Texture* playerTex;
//Create our rectangles
SDL_Rect srcR, destR;

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
	//We use tmp because theis surface is only temporary
	SDL_Surface* tmpSurface = IMG_Load("assets/player.png");
	playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);

	SDL_FreeSurface(tmpSurface);

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

void Game::update()
{
	//srcR we can leave first, dstR we need ot change width and height
	cnt++;
	//This will draw our texture to the top left of our screen
	destR.h = 64;
	destR.w = 64;
	//Now lets move this man, increase x value from zero
	//starts from 0 and goes up every frame
	//Next time we want to cap the framerate
	destR.x = cnt;
	//Notice how the delay reduces the speed of the frames

	std::cout << cnt << std::endl;
}

void Game::render()
{
	SDL_RenderClear(renderer);
	//srcrect rectangle part of rectangle you want to draw
	//First NULL will use entire image, second NULL arg will draw to whole frame
	SDL_RenderCopy(renderer, playerTex, NULL, &destR);
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}