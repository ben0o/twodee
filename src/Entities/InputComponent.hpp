#ifndef INPUTCOMPONENT_H
#define INPUTCOMPONENT_H

#include <SDL2/SDL.h>
#include "Entity.hpp"

class InputComponent
{
public:
	virtual ~InputComponent() {}
	virtual void Update(Entity& entity) = 0;
};


class PlayerInputComponent : public InputComponent
{
public:
	virtual void Update(Entity& entity, double deltaTime)
	{
		entity.xPlayerPos += entity.xPosVel * deltaTime;
		entity.yPlayerPos += entity.yPosVel * deltaTime;
	}
};

#endif