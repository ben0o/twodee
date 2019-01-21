#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include <SDL2/SDL.h>
#include <vector>
#include "structs.hpp"
#include "shape.hpp"
#include "door.hpp"
#include "button.hpp"

class CollisionManager
{
public:
	CollisionManager();
	~CollisionManager();

	void SetCurrSceneCollisions(std::vector<Shape>* cObjects, std::vector<Door>* doors, std::vector<Button>* buttons, int WORLD_WIDTH, int WORLD_HEIGHT);
	std::vector<Shape> GetCurrSceneCollisions();
	void UpdateCollidableObjectsOnScreen();
	void playerCollision(float xVelocity, float yVelocity, float* xNewPos, float* yNewPos, SDL_Rect currentPos);

private:
	std::vector<Shape>* cObjects;
	std::vector<Door>* doors;
	std::vector<Button>* buttons;
	std::vector<Shape> objOnScreen;
	int currWorldWidth, currWorldHeight;

};

#endif