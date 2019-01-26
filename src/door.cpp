#include "door.hpp"

Door::Door()
{

}

Door::~Door()
{

}

void Door::CreateDoor(int x, int y, std::string name, bool open)
{
	Rectangle.x = x;
	Rectangle.y = y;
	Rectangle.h = 10;
	Rectangle.w = 100;
	this->open = open;
	doorName = name;
}

void Door::ToggleDoor(bool isOpen)
{
	this->open = isOpen;
}

SDL_Rect Door::GetDoorBounds()
{
	return Rectangle;
}

bool Door::GetOpen()
{
	return open;
}

std::string Door::GetName()
{
	return doorName;
}

void Door::Draw(SDL_Renderer* p_renderer, Camera* camera)
{
	SDL_Rect ScreenPos;
	ScreenPos.x = Rectangle.x - camera->GetCameraPosition().x;
	ScreenPos.y = Rectangle.y - camera->GetCameraPosition().y;
	ScreenPos.w = Rectangle.w;
	ScreenPos.h = Rectangle.h;

	if (open)
		SDL_SetRenderDrawColor(p_renderer, 0, 255, 0, 255);
	else
		SDL_SetRenderDrawColor(p_renderer, 255, 0, 0, 255);

	SDL_RenderFillRect(p_renderer, &ScreenPos);
}