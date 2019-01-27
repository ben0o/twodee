#ifndef PLAYERINPUTCOMPONENT_H
#define PLAYERINPUTCOMPONENT_H

#include <SDL2/SDL.h>
#include "InputComponent.hpp"

class Player;
class PlayerInputComponent : public InputComponent
{
public:
	virtual void Input(SDL_Event& event, Player& player);
	virtual void Update(Player& player);
private:
	const float PLAYER_VEL = 0.2;
};

#endif