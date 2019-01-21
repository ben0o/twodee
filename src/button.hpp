#ifndef BUTTON_H
#define BUTTON_H

#include "camera.hpp"
#include <SDL2/SDL.h>

class Button
{
public:
	Button();
	~Button();

	void CreateButton(int x, int y, std::string doorTarget);
	SDL_Rect GetButtonBounds();
	std::string GetDoorTarget();

	void Draw(SDL_Renderer* p_renderer, Camera* camera);

private:
	std::string doorTargetName;
	SDL_Rect bBorder;
	SDL_Rect bSwitch;

	SDL_Rect bBounds;
};

#endif