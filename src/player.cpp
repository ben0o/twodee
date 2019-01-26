#include "player.hpp"
#include "scene.hpp"

//static const int WALKING_SPEED = 1;

Player::Player()
{
	// Default constructor.

	// Set sprite coordinates on image file.
	forwardSprite = { 0, 0, 30, 48 }; // X, Y, W, H
	leftSprite = { 0, 48, 30, 48 };
	rightSprite = { 0, 96, 30, 48 };
	backSprite = { 0, 144, 30, 48 };

	currentPos.x = 800;
	currentPos.y = 1050;
	

	playerSize.x = 30;// spriteImgCoords.w;
	playerSize.y = 48;// spriteImgCoords.h;

	velocity.x = 0.0f;
	velocity.y = 0.0f;

	newPosition.x = currentPos.x;
	newPosition.y = currentPos.y;
}
Player::~Player()
{
	// Destructor
}

glm::vec2 Player::GetPosition()
{
	return currentPos;
}

glm::vec2 Player::GetCenter()
{
	return glm::vec2((currentPos.x + (playerSize.x / 2)), currentPos.y + (playerSize.y / 2));
}

glm::vec2 Player::GetVelocity()
{
	return velocity;
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

void Player::Input(SDL_Event &event)
{
	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
			case SDLK_w: velocity.y -= PLAYER_VEL; break; // Forward
			case SDLK_s: velocity.y += PLAYER_VEL; break; // Backward
			case SDLK_a: velocity.x -= PLAYER_VEL; break; // Left
			case SDLK_d: velocity.x += PLAYER_VEL; break; // Right
		}
	}
	if (event.type == SDL_KEYUP)
	{
		switch (event.key.keysym.sym)
		{
			case SDLK_w: velocity.y += PLAYER_VEL; break; // Forward
			case SDLK_s: velocity.y -= PLAYER_VEL; break; // Backward
			case SDLK_a: velocity.x += PLAYER_VEL; break; // Left
			case SDLK_d: velocity.x -= PLAYER_VEL; break; // Right
		}
	}
}

void Player::Update(Camera* camera, Scene* currScene, double deltaTime)
{
	// Get new position
	newPosition.x += velocity.x * deltaTime;
	newPosition.y += velocity.y * deltaTime;

	// Tests collision on new position. If the player is colliding with the edge of the screen, or other objects,
	// the position will be reset.
	SDL_Rect playerBounds = { (int)currentPos.x, (int)currentPos.y, (int)playerSize.x, (int)playerSize.y };

	// --- Test collision with level boundaries. ---
	if ((newPosition.x < 0) || (newPosition.x + playerBounds.w > currScene->GetLevelWidth()))
		newPosition.x -= velocity.x;

	if ((newPosition.y < 0) || (newPosition.y + playerSize.x > currScene->GetLevelHeight()))
		newPosition.y -= velocity.y;

	// --- Test collision with game objects ---
	std::vector<Shape> cObjects = currScene->GetWalls();
	std::vector<Door> doors = currScene->GetDoors();
	std::vector<Button> buttons = currScene->GetButtons();
	
	SDL_Rect currentRect;
	bool collisionX, collisionY;
	int playerWidth, playerHeight, objWidth, objHeight;
	playerWidth = currentPos.x + playerBounds.w;
	playerHeight = currentPos.y + playerBounds.h;

	for (std::vector<Shape>::iterator it = cObjects.begin(); it != cObjects.end(); ++it)
	{
		currentRect = it->GetRect();

		// X-Axis collision
		collisionX = (newPosition.x + playerBounds.w > currentRect.x) && (currentRect.x + currentRect.w > newPosition.x);

		// Y-Axis collision
		collisionY = (newPosition.y + playerBounds.h > currentRect.y) && (currentRect.y + currentRect.h > newPosition.y);

		// If there has been a collision...
		if (collisionX && collisionY)
		{
			objWidth = currentRect.x + currentRect.w;
			objHeight = currentRect.y + currentRect.h;

			// Test if the collision is from the side
			if (
				(currentPos.x <= objWidth || playerWidth >= currentRect.x)
				&& (currentPos.y > currentRect.y && currentPos.y < objHeight)
				|| (playerHeight >= currentRect.y && playerHeight < objHeight)
				|| (currentPos.y <= currentRect.y && playerHeight >= objHeight)
				) // If collision is from the side, move player back to previous position in x-axis.
				newPosition.x -= velocity.x;

			// Test if the collision is from the top or bottom
			if (
				(currentPos.y <= objHeight || playerHeight >= currentRect.y)
				&& (currentPos.x > currentRect.x && currentPos.x < objWidth)
				|| (playerWidth >= currentRect.x && playerWidth < objWidth)
				|| (currentPos.x <= currentRect.x && playerWidth >= objWidth)
				) // If collision is from top or bottom, move player back to previous position in y-Axis.
				newPosition.y -= velocity.y;
		}
	}

	for (std::vector<Door>::iterator it = doors.begin(); it != doors.end(); ++it)
	{
		if (it->GetOpen() == false)
		{
			currentRect = it->GetDoorBounds();

			// X-Axis collision
			collisionX = (newPosition.x + playerBounds.w > currentRect.x) && (currentRect.x + currentRect.w > newPosition.x);

			// Y-Axis collision
			collisionY = (newPosition.y + playerBounds.h > currentRect.y) && (currentRect.y + currentRect.h > newPosition.y);

			if (collisionX && collisionY)
			{
				objWidth = currentRect.x + currentRect.w;
				objHeight = currentRect.y + currentRect.h;

				// Test if the collision is from the side
				if (
					(currentPos.x <= objWidth || playerWidth >= currentRect.x)
					&& (currentPos.y > currentRect.y && currentPos.y < objHeight)
					|| (playerHeight >= currentRect.y && playerHeight < objHeight)
					|| (currentPos.y <= currentRect.y && playerHeight >= objHeight)
					) // If collision is from the side, move player back to previous position in x-axis.
					newPosition.x -= velocity.x;

				// Test if the collision is from the top or bottom
				if (
					(currentPos.y <= objHeight || playerHeight >= currentRect.y)
					&& (currentPos.x > currentRect.x && currentPos.x < objWidth)
					|| (playerWidth >= currentRect.x && playerWidth < objWidth)
					|| (currentPos.x <= currentRect.x && playerWidth >= objWidth)
					) // If collision is from top or bottom, move player back to previous position in y-Axis.
					newPosition.y -= velocity.y;
			}
		}
	}

	for (std::vector<Button>::iterator it = buttons.begin(); it != buttons.end(); ++it)
	{
		currentRect = it->GetButtonBounds();

		// X-Axis collision
		collisionX = (newPosition.x + playerBounds.w > currentRect.x) && (currentRect.x + currentRect.w > newPosition.x);

		// Y-Axis collision
		collisionY = (newPosition.y + playerBounds.h > currentRect.y) && (currentRect.y + currentRect.h > newPosition.y);

		if (collisionX && collisionY)
		{
			//std::cout << "Collision with button." << std::endl;
		}
	}

	// Cast current position to an integer and update the player position.
	currentPos.x = (int)newPosition.x;
	currentPos.y = (int)newPosition.y;

	// Update camera.
	camera->SetCameraPosition(GetCenter());
}

void Player::Draw(SDL_Renderer* p_renderer, Camera* camera)
{
	SDL_Rect newPos = { (int)currentPos.x - camera->GetCameraPosition().x, (int)currentPos.y - camera->GetCameraPosition().y, (int)playerSize.x, (int)playerSize.y }; //  X, Y, W, H

	if (GetVelocity().x < 0)
		SDL_RenderCopy(p_renderer, playerSprite, &leftSprite, &newPos);
	else if (GetVelocity().x > 0)
		SDL_RenderCopy(p_renderer, playerSprite, &rightSprite, &newPos);

	else if (GetVelocity().y > 0)
		SDL_RenderCopy(p_renderer, playerSprite, &forwardSprite, &newPos);
	else if (GetVelocity().y < 0)
		SDL_RenderCopy(p_renderer, playerSprite, &backSprite, &newPos);

	else
		SDL_RenderCopy(p_renderer, playerSprite, &forwardSprite, &newPos);


} 