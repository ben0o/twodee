#ifndef SHAPE_H
#define SHAPE_H

#include "structs.hpp"
#include <SDL2/SDL.h>

class Shape
{
public:
	Shape();
	~Shape();

	void CreateRectangle(int x, int y, int h, int w);
	void Draw(SDL_Renderer* p_renderer);

private:
	SDL_Rect Rectangle;

};

#endif