#ifndef SCENE_H
#define SCENE_H

#include "structs.hpp"
#include "Shape.hpp"
#include "player.hpp"
#include <SDL2/SDL.h>
#include <vector>
#include <iostream>

class Scene
{
	public:
		Scene();
		Scene(Player *player, SDL_Rect *camera);
		~Scene();

		void CreateRectangle(int x, int y, int h, int w);

		int GetLevelWidth();
		int GetLevelHeight();

		void Update(int cameraX, int cameraY);
		void Draw(SDL_Renderer* p_renderer);

private:
	// World (level) dimensions
	//const int WORLD_WIDTH = 1500;
	//const int WORLD_HEIGHT = 768;

	// Vector of shapes, created using SDL functions.
	std::vector<Shape> walls;

	// Player and camera pointers
	Player *playerPtr;
	SDL_Rect *cameraPtr;
};

#endif