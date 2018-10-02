#include "engine.hpp"

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

int main(int argv, char** args) 
{
	Engine engine;
	engine.Run();
	return 0;
}