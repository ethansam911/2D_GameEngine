#include "Game.h"

Game *game = nullptr;

int main(int argc, char *argv[])
{
	//Capping framerate
	//60 is good because this is close to the refresh rate of our monitors
	const int FPS = 60;
	     
	//If the frame rate is at 60 FPS, 
	//each frame must take no less than 1/60th of a second.

	//We need to know how long a frame should last
	const int frameDelay = 1000 / FPS;

	//unsigned integer 32bit 2^32 negative or positive
	//Massive integer
	Uint32 frameStart;
	int frameTime;
	    
	game = new Game();
	//Since 600 doesn't divide by 32, we will pick 640
	game->init("GameWindow", 800, 640, false);

	while (game->running())  
	{
		//Get the current runningtime in ms
		//Remember from minecraft!
		//How many ms its been since we first initialized SDL
		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		//We get the amount of ticks since we first started (frameStart) 
		//and subtract it from the current amount of ticks
		//Total time of handleEvents(), update(), and render()
		frameTime = SDL_GetTicks() - frameStart;

		//We know how long frames take, we can check to see how long we need to delay further
		if (frameDelay > frameTime)//frameDelay is set 1000/60, if longer than frameTime, delay the frameTime to catch up with frameDelay
		{
			// Delay by the difference between the time of above events 
			SDL_Delay(frameDelay - frameTime);
			//The result is much smoother because we allow for the compensation of 
			//time between updated objects and visual change 
		}
	}
	game->clean();
	return 0;
}