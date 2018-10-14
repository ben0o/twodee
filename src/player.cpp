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

	yPos = currentPos.y;
	std::cout << "Y: " << yPos << std::endl;
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

void Player::Step(Direction dir, bool enabled, double dt)
{
	switch (dir)
	{
	case FORWARD:
		moveDir[FORWARD] = enabled; break;
	case BACKWARD:
		moveDir[BACKWARD] = enabled; break;
	case LEFT:
		moveDir[LEFT] = enabled; break;
	case RIGHT:
		moveDir[RIGHT] = enabled; break;
	default:
			break;
	};

	if ((moveDir[FORWARD] && moveDir[BACKWARD]) || (moveDir[LEFT] && moveDir[RIGHT]))
		return;
	if (moveDir[FORWARD])
		currentPos.y -= 1;
	if (moveDir[BACKWARD])
		currentPos.y += 1;
	if (moveDir[LEFT])
		currentPos.x -= 1;
	if (moveDir[RIGHT])
		currentPos.x += 1;
}

//void Player::Step(double dt)
//{
//	//if ((moveDir[FORWARD] && moveDir[BACKWARD]) || (moveDir[LEFT] && moveDir[RIGHT]))
//		//return;
//	if (moveDir[FORWARD] == true)
//		currentPos.y++;//= currentPos.y + (dt * WALKING_SPEED);
//	if (moveDir[BACKWARD] == true)
//		currentPos.y = currentPos.y - (dt * WALKING_SPEED);
//	if (moveDir[LEFT] == true)
//		currentPos.x = currentPos.x - (dt * WALKING_SPEED);
//	if (moveDir[RIGHT] == true)
//		currentPos.x = currentPos.x + (dt * WALKING_SPEED);
//}

void Player::Draw(SDL_Renderer* p_renderer)
{
	SDL_RenderClear(p_renderer);
	SDL_RenderCopy(p_renderer, playerSprite, &spriteImgCoords, &currentPos);
	SDL_RenderPresent(p_renderer);
}