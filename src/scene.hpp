#ifndef SCENE_H
#define SCENE_H

#include "structs.hpp"
#include "Shape.hpp"
#include "player.hpp"
#include "collisionManager.hpp"
#include <SDL2/SDL.h>
#include <vector>
#include <iostream>

class Scene
{
	public:
		Scene();
		Scene(Player *player, Camera *camera, CollisionManager *cMgr);
		~Scene();

		void CreateRectangle(int x, int y, int h, int w);

		int GetLevelWidth();
		int GetLevelHeight();

		std::vector<Shape> GetWalls();

		void Update(int cameraX, int cameraY);
		void Draw(SDL_Renderer* p_renderer);

private:
	// Vector of shapes, created using SDL functions.
	std::vector<Shape> walls;

	// Level Size
	int WORLD_WIDTH;
	int WORLD_HEIGHT;

	// Player and camera pointers
	Player *playerPtr;
	Camera *cameraPtr;

	CollisionManager* collisionMgr;
};

#endif