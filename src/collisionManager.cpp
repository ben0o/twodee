#include "collisionManager.hpp"

CollisionManager::CollisionManager()
{

}

CollisionManager::~CollisionManager()
{

}

void CollisionManager::SetCurrSceneCollisions(std::vector<Shape>* cObjects, int WORLD_WIDTH, int WORLD_HEIGHT)
{
	this->cObjects = cObjects;
	currWorldWidth = WORLD_WIDTH;
	currWorldHeight = WORLD_HEIGHT;
}

void CollisionManager::UpdateCollidableObjectsOnScreen()
{
	objOnScreen.clear();
	SDL_Rect currRect;

	for (std::vector<Shape>::iterator it = cObjects->begin(); it != cObjects->end(); ++it)
	{
		currRect = it->GetRect();

		if ((currRect.x > 0 && currRect.x + currRect.w < SCREEN_WIDTH) && (currRect.y > 0 && currRect.y + currRect.h < SCREEN_HEIGHT))
			objOnScreen.push_back((&it));
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

	// --- Test collision with game objects. ---
	for (std::vector<Shape>::iterator it = cObjects->begin(); it != cObjects->end(); ++it)
	{
		currentRect = it->GetRect();

		// X-Axis collision
		collisionX = ((*xNewPos) + currentPos.w > currentRect.x) && (currentRect.x + currentRect.w > (*xNewPos));

		// Y-Axis collision
		collisionY = ((*yNewPos) + currentPos.h > currentRect.y) && (currentRect.y + currentRect.h > (*yNewPos));

		if (collisionX && collisionY)
		{
			(*xNewPos) -= xVelocity;
			(*yNewPos) -= yVelocity;
		}
	}
}