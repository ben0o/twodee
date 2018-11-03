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
			if (moveDir[FORWARD])
				yPosVel -= PLAYER_VEL;
			else
				yPosVel = 0;
			std::cout << "yPosVel: " << yPosVel << std::endl;
			break;
		}

		case BACKWARD:
		{
			moveDir[BACKWARD] = enabled;
			if (moveDir[BACKWARD])
				yPosVel += PLAYER_VEL;
			else
				yPosVel = 0;
			std::cout << "yPosVel: " << yPosVel << std::endl;
			break;
		}

		case LEFT:
		{
			moveDir[LEFT] = enabled;
			if (moveDir[LEFT])
				xPosVel -= PLAYER_VEL;
			else
				xPosVel = 0;
			std::cout << "xPosVel: " << xPosVel << std::endl;
			break;
		}

		case RIGHT:
		{
			moveDir[RIGHT] = enabled;
			if (moveDir[RIGHT])
				xPosVel += PLAYER_VEL;
			else
				xPosVel = 0;
			std::cout << "xPosVel: " << xPosVel << std::endl;
			break;
		}
	};

}

void Player::Update(float timeStep)
{
	// Move the player left or right.
	// *****************
	// The timeStep variable is commented out for now, as the character can't be moved right or down.
	// I suspect the resulting x/yPosOffset value is between 0.0 and -0.5, and as SDL rounds to whole numbers, it's being rounded down to 0.
	// *****************
	xPosOffset = xPosVel;// * timeStep; 

	// Move the player forward or backward.
	yPosOffset = yPosVel;// *timeStep;

	if ((currentPos.x += xPosOffset) >= 0) // If the X position is equal to or larger than 0 (doesn't go off the left side of the screen)..
		currentPos.x += xPosOffset;
	else
		currentPos.x = 0;

	if ((currentPos.y += yPosOffset) >= 0) // If the Y position is equal to or larger than 0 (doesn't go off the right side of the screen)..
		currentPos.y += yPosOffset;
	else
		currentPos.y = 0;
}

void Player::Draw(SDL_Renderer* p_renderer)
{
	SDL_RenderClear(p_renderer);
	SDL_RenderCopy(p_renderer, playerSprite, &spriteImgCoords, &currentPos);
	SDL_RenderPresent(p_renderer);
}