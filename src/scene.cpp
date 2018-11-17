#include "scene.hpp"

Scene::Scene()
{
	// Default Constructor
	wall.x = 300;
	wall.y = 40;
	wall.w = 40;
	wall.h = 400;
}

Scene::~Scene()
{
	// Destructor
}

void Scene::Draw(SDL_Renderer* p_renderer)
{
	// Clear Screen
	SDL_SetRenderDrawColor(p_renderer, 255, 0, 0, 255);
	SDL_RenderClear(p_renderer);

	// Draw wall
	SDL_SetRenderDrawColor(p_renderer, 0, 0, 255, 255);
	SDL_RenderFillRect(p_renderer, &wall);
}