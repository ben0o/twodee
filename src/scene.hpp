#ifndef SCENE_H
#define SCENE_H

#include "structs.hpp"
#include <SDL2/SDL.h>
#include <vector>

class Scene
{
	public:
		Scene();
		~Scene();

		void CreateRectangle(int x, int y, int h, int w);

		void Draw(SDL_Renderer* p_renderer);

private:
	// Level dimensions
	const int LEVEL_WIDTH = 1280;
	const int LEVEL_HEIGHT = 960;

	SDL_Rect wall;
	std::vector<SDL_Rect> Rectangles;
};

#endif