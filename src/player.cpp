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

	xPosVel = 0;
	yPosVel = 0;

	xPlayerPos = currentPos.x;
	yPlayerPos = currentPos.y;

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
	if (enabled)
	{
		switch (dir)
		{
			case FORWARD:	yPosVel -= PLAYER_VEL; break;
			case BACKWARD:	yPosVel += PLAYER_VEL; break;
			case LEFT:		xPosVel -= PLAYER_VEL; break;
			case RIGHT:		xPosVel += PLAYER_VEL; break;
		};
	}
	else
	{
		switch (dir)
		{
			case FORWARD:	yPosVel += PLAYER_VEL; break;
			case BACKWARD:	yPosVel -= PLAYER_VEL; break;
			case LEFT:		xPosVel += PLAYER_VEL; break;
			case RIGHT:		xPosVel -= PLAYER_VEL; break;
		};
	}

}

void Player::Update(double deltaTime)
{
	//float newPosX, newPosY;
	//float xPosOffset, yPosOffset;

	//newPosX = currentPos.x;
	//newPosY = currentPos.y;

	//xPosOffset = newPosX + (xPosVel * (deltaTime / 1000));
	//yPosOffset = newPosY + (yPosVel * (deltaTime / 1000));

	float xPosOffset = xPosVel * deltaTime / 1000;
	float yPosOffset = yPosVel * deltaTime / 1000;

	xPlayerPos += xPosOffset;
	yPlayerPos += yPosOffset;

	//currentPos.x += xPosVel;
	//currentPos.y += yPosVel;
	//
	//if ((currentPos.x < 0) || (currentPos.x + currentPos.w > SCREEN_WIDTH))
	//	currentPos.x -= xPosVel;
	//
	//if ((currentPos.y < 0) || (currentPos.y + currentPos.h > SCREEN_HEIGHT))
	//	currentPos.y -= yPosVel;
	//
	std::cout << "deltaTime: " << deltaTime << std::endl;
	//std::cout << "xPos: " << xPlayerPos << std::endl;
}

void Player::Draw(SDL_Renderer* p_renderer)
{
	SDL_RenderCopy(p_renderer, playerSprite, &spriteImgCoords, &currentPos);
}