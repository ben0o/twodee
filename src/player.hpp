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
	const float PLAYER_VEL = 0.2;

	// Player direction flags
	enum Direction { FORWARD, BACKWARD, LEFT, RIGHT };

	Player();
	~Player();

	BoundingBox GetBoundingBox();
	float GetPosX();
	float GetPosY();
	float GetCenterX();
	float GetCenterY();

	void LoadPlayerSprite(SDL_Renderer* p_renderer, std::string imagePath);
	void SetDirection(Direction dir, bool enabled);
	void Update(double deltaTime);
	void Draw(SDL_Renderer* p_renderer);

private:
	SDL_Texture* playerSprite;
	SDL_Rect spriteImgCoords, currentPos;

	bool moveDir[4];

	// Player velocity
	float xPosVel, yPosVel;

	// Player position on the screen.
	float xPlayerPos, yPlayerPos;

	// Player position in the world
	float xPlayerWorldPos, yPlayerWorldPos;

	BoundingBox playerBB;
};

#endif