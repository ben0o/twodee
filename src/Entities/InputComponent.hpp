#ifndef INPUTCOMPONENT_H
#define INPUTCOMPONENT_H

#include <SDL2/SDL.h>

class Player;
class InputComponent
{
public:
	virtual ~InputComponent() {};
	virtual void Input(SDL_Event& event, Player& player) = 0;
	virtual void Update(Player& player) = 0;
};

#endif