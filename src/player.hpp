#ifndef PLAYER_H
#define PLAYER_H

#include "structs.hpp"
#include "collisionManager.hpp"
#include "camera.hpp"
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

	float GetPosX();
	float GetPosY();
	float GetCenterX();
	float GetCenterY();
	float GetXVelocity();
	float GetYVelocity();
	SDL_Rect GetPlayerBounds();

	void LoadPlayerSprite(SDL_Renderer* p_renderer, std::string imagePath);
	void SetDirection(Direction dir, bool enabled);
	void setCollisionManager(CollisionManager* collisionMgr);

	void CalculateNewPosition(double deltaTime);
	void Update(Camera* camera);
	void Draw(SDL_Renderer* p_renderer, Camera* camera);

private:
	SDL_Texture* playerSprite;
	SDL_Rect spriteImgCoords, currentPos;// , newPos;
	SDL_Rect newCamera; // Buffer camera

	bool moveDir[4];

	CollisionManager* collisionMgr;

	// Player velocity
	float xPosVel, yPosVel;

	// Player position - calculated before collision detection.
	float xPlayerPos, yPlayerPos;
};

#endif