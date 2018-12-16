#ifndef SHAPE_H
#define SHAPE_H

#include "structs.hpp"
#include "camera.hpp"
#include <SDL2/SDL.h>

class Shape
{
public:
	Shape();
	~Shape();

	void CreateRectangle(int x, int y, int h, int w);

	SDL_Rect GetRect();

	void UpdateRectangle(int cameraX, int cameraY);
	void Draw(SDL_Renderer* p_renderer, Camera* camera);

private:
	SDL_Rect Rectangle;

};

#endif