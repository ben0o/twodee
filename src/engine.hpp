#ifndef ENGINE_H
#define ENGINE_H

#include "controller.hpp"
#include "controllerMenu.hpp"
#include "controllerGame.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>


class Engine
{
public:
    Engine();
    ~Engine();
    
	void Run();
    void Input(SDL_Event &event, double dt);
	void Update(float timeStep);
	void Draw();
	
	void ToggleMenu();
    
private:
    // Controllers
    Controller* p_cntrMenu;
    Controller* p_cntrGame;
    Controller* p_cntrCurrent;
    
    // SDL Render Window
    SDL_Window* p_window;
    SDL_Renderer* p_renderer;
    
    bool bShowMenu;
    bool bRunning;

};

#endif