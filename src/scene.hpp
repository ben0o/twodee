#ifndef SCENE_H
#define SCENE_H

#include "structs.hpp"
#include <SDL2/SDL.h>

class Scene
{
	public:
		Scene();
		~Scene();

		void Draw(SDL_Renderer* p_renderer);

private:
	// Level dimensions
	const int LEVEL_WIDTH = 1280;
	const int LEVEL_HEIGHT = 960;

	SDL_Rect wall;
};

#endif