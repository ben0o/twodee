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
	currentPos.x = (SCREEN_WIDTH / 2) - (spriteImgCoords.w / 2);
	currentPos.y = (SCREEN_HEIGHT / 2) - (spriteImgCoords.h / 2);
	currentPos.w = spriteImgCoords.w;
	currentPos.h = spriteImgCoords.h;

	xPosVel = 0.0f;
	yPosVel = 0.0f;

	xPlayerPos = currentPos.x;
	yPlayerPos = currentPos.y;

	playerBB.left = xPlayerPos;
	playerBB.right = xPlayerPos + currentPos.w;
	playerBB.top = yPlayerPos;
	playerBB.bottom = yPlayerPos + currentPos.h;
}
Player::~Player()
{
	// Destructor
}

BoundingBox Player::GetBoundingBox()
{
	return playerBB;
}

float Player::GetPosX()
{
	return xPlayerPos;
}

float Player::GetPosY()
{
	return yPlayerPos;
}

float Player::GetCenterX()
{
	return xPlayerPos - (currentPos.w / 2);
}

float Player::GetCenterY()
{
	return yPlayerPos + (currentPos.h / 2);
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
	// Set new float position
	xPlayerPos += xPosVel * deltaTime;
	yPlayerPos += yPosVel * deltaTime;

	// Test collision with edges of screen
	if ((xPlayerPos < 0) || (xPlayerPos + currentPos.w > SCREEN_WIDTH))
		xPlayerPos -= xPosVel;
	
	if ((yPlayerPos < 0) || (yPlayerPos + currentPos.h > SCREEN_HEIGHT))
		yPlayerPos -= yPosVel;

	// Cast current position to an integer and update the sprite position
	currentPos.x = (int)xPlayerPos;
	currentPos.y = (int)yPlayerPos;

	playerBB.left = xPlayerPos;
	playerBB.right = xPlayerPos + currentPos.w;
	playerBB.top = yPlayerPos;
	playerBB.bottom = yPlayerPos + currentPos.h;
}

void Player::Draw(SDL_Renderer* p_renderer)
{
	SDL_RenderCopy(p_renderer, playerSprite, &spriteImgCoords, &currentPos);
} 