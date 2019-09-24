//Map
#include "Game.h"

class Map
{
public:
	//Constructor
	Map();
	//Destructor
	~Map();

	void LoadMap(int arr[20][25]);
	void DrawMap();

private:
	//SDL_Rect is a structure that contains the definition of a rectangle
	// Contains an origin at the upper left
	SDL_Rect src, dest;


	//Pointers to the texture address
	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;

	//2D Array for the actual map
	int map[20][25];

};
