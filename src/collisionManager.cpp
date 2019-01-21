#include "collisionManager.hpp"

CollisionManager::CollisionManager()
{

}

CollisionManager::~CollisionManager()
{

}

void CollisionManager::SetCurrSceneCollisions(std::vector<Shape>* cObjects, std::vector<Door>* doors, std::vector<Button>* buttons, int WORLD_WIDTH, int WORLD_HEIGHT)
{
	this->cObjects = cObjects;
	this->doors = doors;
	this->buttons = buttons;
	currWorldWidth = WORLD_WIDTH;
	currWorldHeight = WORLD_HEIGHT;
}

std::vector<Shape> CollisionManager::GetCurrSceneCollisions()
{
	return objOnScreen;
}

void CollisionManager::UpdateCollidableObjectsOnScreen()
{
	objOnScreen.clear();
	SDL_Rect currRect;

	for (std::vector<Shape>::iterator it = cObjects->begin(); it != cObjects->end(); ++it)
	{
		Shape newShape = *it;
		currRect = newShape.GetRect();
		
		if ((currRect.x > 0 && currRect.x + currRect.w < SCREEN_WIDTH) && (currRect.y > 0 && currRect.y + currRect.h < SCREEN_HEIGHT))
			objOnScreen.push_back(newShape);
	}
}

void CollisionManager::playerCollision(float xVelocity, float yVelocity, float* xNewPos, float* yNewPos, SDL_Rect currentPos)
{
	// --- Test collision with level boundaries. ---
	if (((*xNewPos) < 0) || ((*xNewPos) + currentPos.w > currWorldWidth))
		(*xNewPos) -= xVelocity;

	if (((*yNewPos) < 0) || ((*yNewPos) + currentPos.h > currWorldHeight))
		(*yNewPos) -= yVelocity;

	SDL_Rect currentRect;
	bool collisionX, collisionY;

	int playerWidth, playerHeight, objWidth, objHeight;
	playerWidth = currentPos.x + currentPos.w;
	playerHeight = currentPos.y + currentPos.h;

	// --- Test collision with game objects. ---
	for (std::vector<Shape>::iterator it = cObjects->begin(); it != cObjects->end(); ++it)
	{
		currentRect = it->GetRect();

		// X-Axis collision
		collisionX = ((*xNewPos) + currentPos.w > currentRect.x) && (currentRect.x + currentRect.w > (*xNewPos));

		// Y-Axis collision
		collisionY = ((*yNewPos) + currentPos.h > currentRect.y) && (currentRect.y + currentRect.h > (*yNewPos));

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
				(*xNewPos) -= xVelocity;

			// Test if the collision is from the top or bottom
			if (
				(currentPos.y <= objHeight || playerHeight >= currentRect.y)
				&& (currentPos.x > currentRect.x && currentPos.x < objWidth)
				|| (playerWidth >= currentRect.x && playerWidth < objWidth)
				|| (currentPos.x <= currentRect.x && playerWidth >= objWidth)
				) // If collision is from top or bottom, move player back to previous position in y-Axis.
				(*yNewPos) -= yVelocity;
		}
	}


	for (std::vector<Door>::iterator it = doors->begin(); it != doors->end(); ++it)
	{
		currentRect = it->GetDoorBounds();

		// X-Axis collision
		collisionX = ((*xNewPos) + currentPos.w > currentRect.x) && (currentRect.x + currentRect.w > (*xNewPos));

		// Y-Axis collision
		collisionY = ((*yNewPos) + currentPos.h > currentRect.y) && (currentRect.y + currentRect.h > (*yNewPos));

		if (collisionX && collisionY && it->GetOpen() == false)
		{
			(*xNewPos) -= xVelocity;
			(*yNewPos) -= yVelocity;
		}
	}

	for (std::vector<Button>::iterator it = buttons->begin(); it != buttons->end(); ++it)
	{
		currentRect = it->GetButtonBounds();

		// X-Axis collision
		collisionX = ((*xNewPos) + currentPos.w > currentRect.x) && (currentRect.x + currentRect.w > (*xNewPos));

		// Y-Axis collision
		collisionY = ((*yNewPos) + currentPos.h > currentRect.y) && (currentRect.y + currentRect.h > (*yNewPos));

		if (collisionX && collisionY)
		{
			//std::cout << "Collision with button." << std::endl;
		}
	}
}