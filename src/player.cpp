#include "player.hpp"

static const int WALKING_SPEED = 1;

Player::Player()
{
	// Default constructor.

	// Set sprite coordinates on image file.
	spriteImgCoords.x = 0;
	spriteImgCoords.y = 0;
	spriteImgCoords.w = 30;
	spriteImgCoords.h = 48;

	// Set default position of player sprite - center of the screen.
	currentPos.x = 1024 / 2;
	currentPos.y = 768 / 2;
	currentPos.w = spriteImgCoords.w;
	currentPos.h = spriteImgCoords.h;

	xPosOffset = 0;
	yPosOffset = 0;
	xPosVel = 0;
	yPosVel = 0;

	counter = 0;
}
Player::~Player()
{
	// Destructor
}

void Player::LoadPlayerSprite(SDL_Renderer* p_renderer, std::string imagePath)
{
	// Load PNG file
	SDL_Surface* loadedSurface = IMG_Load(imagePath.c_str());
	if (loadedSurface == NULL)
		std::cout << "Unable to load image." << std::endl;
	else
	{
		// Convert surface to texture
		playerSprite = SDL_CreateTextureFromSurface(p_renderer, loadedSurface);

		// Delete surface
		SDL_FreeSurface(loadedSurface);
	}
}

void Player::SetDirection(Direction dir, bool enabled)
{
	switch (dir)
	{
		case FORWARD:
		{
			moveDir[FORWARD] = enabled; 
			if (enabled)
				yPosVel += PLAYER_VEL;
			else
				yPosVel -= PLAYER_VEL;
				//yPosVel = 0;
			break;
		}
		case BACKWARD:
		{
			moveDir[BACKWARD] = enabled;
			if (enabled)
				yPosVel -= PLAYER_VEL;
			else
				yPosVel += PLAYER_VEL;
				//yPosVel = 0;
			break;
		}
		case LEFT:
		{
			moveDir[LEFT] = enabled;
			if (enabled)
				xPosVel -= PLAYER_VEL;
			else
				//xPosVel += PLAYER_VEL;
				xPosVel = 0;
			break;
		}
		case RIGHT:
		{
			moveDir[RIGHT] = enabled;
			if (enabled)
				xPosVel += PLAYER_VEL;
			else
				//xPosVel -= PLAYER_VEL;
				xPosVel = 0;
			break;
		}
	};
}


void Player::Update(float timeStep)
{
	// Move the player left or right.
	xPosOffset += xPosVel * timeStep;

	// Move the player forward or backward.
	yPosOffset += yPosVel * timeStep;

	currentPos.x += xPosOffset;
	currentPos.y += yPosOffset;
}

void Player::Draw(SDL_Renderer* p_renderer)
{
	SDL_RenderClear(p_renderer);
	SDL_RenderCopy(p_renderer, playerSprite, &spriteImgCoords, &currentPos);
	SDL_RenderPresent(p_renderer);
}