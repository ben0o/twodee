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
	//currentPos.x = (SCREEN_WIDTH / 2) - (spriteImgCoords.w / 2);
	//currentPos.y = (SCREEN_HEIGHT / 2) - (spriteImgCoords.h / 2);
	currentPos.x = 800;
	currentPos.y = 700;
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

SDL_Rect Player::GetPlayerBounds()
{
	return currentPos;
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

void Player::setCollisionManager(CollisionManager* cMgr)
{
	collisionMgr = cMgr;
}

void Player::CalculateNewPosition(double deltaTime)
{
	// Set new float position
	xPlayerPos += xPosVel * deltaTime;
	yPlayerPos += yPosVel * deltaTime;

	// Tests collision. If the player is colliding with the edge of the screen, or other objects,
	// the position will be reset.
	collisionMgr->playerCollision(xPosVel, yPosVel, &xPlayerPos, &yPlayerPos, currentPos);

}

void Player::Update(Camera* camera)
{
	// Cast current position to an integer and update the player position.
	currentPos.x = (int)xPlayerPos;
	currentPos.y = (int)yPlayerPos;

	// Update camera.
	camera->SetCameraPosition((int)GetCenterX(), (int)GetCenterY());
}

void Player::Draw(SDL_Renderer* p_renderer, Camera* camera)
{
	SDL_Rect newPos = currentPos;
	newPos.x -= camera->GetCameraPosition().x;
	newPos.y -= camera->GetCameraPosition().y;

	SDL_RenderCopy(p_renderer, playerSprite, &spriteImgCoords, &newPos);
} 