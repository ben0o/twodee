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

SDL_Rect Shape::GetRect()
{
	return Rectangle;
}

void Shape::UpdateRectangle(int cameraX, int cameraY)
{
	//Rectangle.x = cameraX;
	//Rectangle.y = cameraY;
}

void Shape::Draw(SDL_Renderer* p_renderer, Camera* camera)
{
	SDL_Rect ScreenPos;
	ScreenPos.x = Rectangle.x - camera->GetCameraPosition().x;
	ScreenPos.y = Rectangle.y - camera->GetCameraPosition().y;
	ScreenPos.w = Rectangle.w;
	ScreenPos.h = Rectangle.h;
	SDL_SetRenderDrawColor(p_renderer, 0, 0, 255, 255);
	SDL_RenderFillRect(p_renderer, &ScreenPos);
}