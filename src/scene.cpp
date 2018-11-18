#include "scene.hpp"

Scene::Scene()
{
	// Default Constructor
}

Scene::~Scene()
{
	// Destructor
}

void Scene::CreateRectangle(int x, int y, int h, int w)
{
	SDL_Rect newRect;
	newRect.x = x;
	newRect.y = y;
	newRect.w = w;
	newRect.h = h;

	Rectangles.push_back(newRect);
}

void Scene::Draw(SDL_Renderer* p_renderer)
{
	// Clear Screen
	SDL_SetRenderDrawColor(p_renderer, 255, 255, 255, 255);
	SDL_RenderClear(p_renderer);
	
	// Draw wall
	SDL_SetRenderDrawColor(p_renderer, 0, 0, 255, 255);

	for (int i = 0; i < Rectangles.size(); i++)
	{
		SDL_RenderFillRect(p_renderer, &Rectangles[i]);
	}
}