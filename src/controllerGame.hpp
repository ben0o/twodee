#ifndef CONTROLLERGAME_H
#define CONTROLLERGAME_H

#include "controller.hpp"
#include <SDL2/SDL.h>
#include <string>
 
class ControllerGame : public Controller
{
public:
	ControllerGame();
	~ControllerGame();

	virtual void Update(double);
	virtual void Draw(SDL_Renderer*);
	virtual void LoadScene(std::string);	
};
#endif