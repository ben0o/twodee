#include "Shape.hpp"

Shape::Shape()
{
	// Default constructor
}

Shape::~Shape()
{
	// Destructor
}

void Shape::CreateRectangle(int x, int y, int h, int w)
{
	Rectangle.x = x;
	Rectangle.y = y;
	Rectangle.w = w;
	Rectangle.h = h;
}

void Shape::Draw(SDL_Renderer* p_renderer)
{
	SDL_SetRenderDrawColor(p_renderer, 0, 0, 255, 255);
	SDL_RenderFillRect(p_renderer, &Rectangle);
}