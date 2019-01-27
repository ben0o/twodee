#ifndef AIINPUTCOMPONENT_H
#define AIINPUTCOMPONENT_H

#include <SDL2/SDL.h>
#include "InputComponent.hpp"

class Player;

class AIInputComponent : public InputComponent
{
public:
	virtual void Input(SDL_Event& event, Player& player);
	virtual void Update(Player& player);
private:
	const float PLAYER_VEL = 0.15;
	const float targetA = 900;
	const float targetB = 700;
};

#endif