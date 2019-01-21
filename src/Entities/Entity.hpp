#ifndef ENTITY_H
#define ENTITY_H

#include <SDL2/SDL.h>
#include "InputComponent.hpp"

enum {
	PLAYER, SPAWNPOINT
};

class Entity
{
public:
	// Orientation/Direction.
	enum Direction { FORWARD, BACKWARD, LEFT, RIGHT };
	
	Entity();
private:
	SDL_Rect currentPos;
};

#endif