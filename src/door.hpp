#ifndef DOOR_H
#define DOOR_H

#include "camera.hpp"
#include <SDL2/SDL.h>

class Door
{
public:
	Door();
	~Door();

	void CreateDoor(int x, int y, std::string name, bool open);
	SDL_Rect GetDoorBounds();
	bool GetOpen();
	std::string GetName();

	void Draw(SDL_Renderer* p_renderer, Camera* camera);

private:
	SDL_Rect Rectangle;
	std::string doorName;
	bool open;
};

#endif