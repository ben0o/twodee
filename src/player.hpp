#ifndef PLAYER_H
#define PLAYER_H

#include "structs.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>

class Player
{
public:

	//Player sprite dimensions
	static const int PLAYER_WIDTH = 30;
	static const int PLAYER_HEIGHT = 48;

	// Maximum player velocity (walking speed)
	static const int PLAYER_VEL = 1;

	// Player direction flags
	enum Direction { FORWARD, BACKWARD, LEFT, RIGHT };

	Player();
	~Player();

	void LoadPlayerSprite(SDL_Renderer* p_renderer, std::string imagePath);
	void SetDirection(Direction dir, bool enabled);
	void Update(float timeStep);
	void Draw(SDL_Renderer* p_renderer);

private:
	SDL_Texture* playerSprite;
	SDL_Rect spriteImgCoords, currentPos;

	int yPos;

	bool moveDir[4];

	// Position offsets
	float xPosOffset, yPosOffset;

	// Player velocity
	float xPosVel, yPosVel;

	int counter;
};

#endif