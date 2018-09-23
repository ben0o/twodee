#ifndef ENGINE_H
#define ENGINE_H

#include "controller.hpp"
#include "controllerMenu.hpp"
#include "controllerGame.hpp"
#include <SDL2/SDL.h>
#include <iostream>


class Engine
{
public:

	void Run();
	void Update(double);
	void Draw();
	
	void ToggleMenu();
	
	Controller* p_cntrMenu;
	Controller* p_cntrGame;
	Controller* p_cntrCurrent;
	
	SDL_Window* p_window;
	SDL_Renderer* p_renderer;
	bool bShowMenu;
};

#endif