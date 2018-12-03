#ifndef SCENE_H
#define SCENE_H

#include "structs.hpp"
#include "Shape.hpp"
#include <SDL2/SDL.h>
#include <vector>
#include <iostream>

class Scene
{
	public:
		Scene();
		~Scene();

		void CreateRectangle(int x, int y, int h, int w);

		int GetLevelWidth();
		int GetLevelHeight();

		void Update(int cameraX, int cameraY);
		void Draw(SDL_Renderer* p_renderer);

private:
	// Level dimensions
	const int LEVEL_WIDTH = 1280;
	const int LEVEL_HEIGHT = 960;

	// Vector of shapes, created using SDL functions.
	std::vector<Shape> walls;
};

#endif