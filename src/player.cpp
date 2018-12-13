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
	//currentPos.x = 600;
	currentPos.y = (SCREEN_HEIGHT / 2) - (spriteImgCoords.h / 2);
	currentPos.w = spriteImgCoords.w;
	currentPos.h = spriteImgCoords.h;

	xPosVel = 0.0f;
	yPosVel = 0.0f;

	xPlayerPos = currentPos.x;
	yPlayerPos = currentPos.y;
}
Player::~Player()
{
	// Destructor
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
	return xPlayerPos + (currentPos.w / 2);
}

float Player::GetCenterY()
{
	return yPlayerPos + (currentPos.h / 2);
}

float Player::GetXVelocity()
{
	return xPosVel;
}

float Player::GetYVelocity()
{
	return yPosVel;
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

void Player::Update(double deltaTime, SDL_Rect* camera)
{
	// Set new float position
	xPlayerPos += xPosVel * deltaTime;
	yPlayerPos += yPosVel * deltaTime;

	// Test collision with edges of screen
	if ((xPlayerPos < 0) || (xPlayerPos + currentPos.w > WORLD_WIDTH))
		xPlayerPos -= xPosVel;
	
	if ((yPlayerPos < 0) || (yPlayerPos + currentPos.h > WORLD_HEIGHT))
		yPlayerPos -= yPosVel;

	// Reposition camera
	camera->x = (int)(GetCenterX() - (SCREEN_WIDTH / 2));
	camera->y = (int)(GetCenterY() - (SCREEN_HEIGHT / 2));

	// Test if camera goes out of bounds.
	if (camera->x < 0) camera->x = 0;
	if (camera->x > (WORLD_WIDTH - camera->w)) camera->x = WORLD_WIDTH - camera->w;
	
	if (camera->y < 0) camera->y = 0;
	if (camera->y > (WORLD_HEIGHT - camera->h)) camera->y = WORLD_HEIGHT - camera->h;

	// Cast current position to an integer and update the player position
	currentPos.x = (int)xPlayerPos;
	currentPos.y = (int)yPlayerPos;

}

void Player::Draw(SDL_Renderer* p_renderer, SDL_Rect* camera)
{
	SDL_Rect newPos = currentPos;
	newPos.x -= camera->x;
	newPos.y -= camera->y;

	SDL_RenderCopy(p_renderer, playerSprite, &spriteImgCoords, &newPos);
} 