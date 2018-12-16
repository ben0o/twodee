#include "scene.hpp"

Scene::Scene()
{
	// Default Constructor
}

Scene::Scene(Player *player, Camera *camera, CollisionManager *cMgr)
{
	WORLD_WIDTH = 1600;
	WORLD_HEIGHT = 900;

	playerPtr = player;
	cameraPtr = camera;
	camera->SetCameraBounds(WORLD_WIDTH, WORLD_HEIGHT);

	collisionMgr = cMgr;
	collisionMgr->SetCurrSceneCollisions(&walls, WORLD_WIDTH, WORLD_HEIGHT);

	playerPtr->setCollisionManager(collisionMgr);
}

Scene::~Scene()
{
	// Destructor
}

void Scene::CreateRectangle(int x, int y, int h, int w)
{
	Shape newShape;
	newShape.CreateRectangle(x, y, h, w);
	walls.push_back(newShape);
}

int Scene::GetLevelWidth()
{
	return WORLD_WIDTH;
}

int Scene::GetLevelHeight()
{
	return WORLD_HEIGHT;
}

std::vector<Shape> Scene::GetWalls()
{
	return walls;
}

void Scene::Update(int cameraX, int cameraY)
{

}

void Scene::Draw(SDL_Renderer* p_renderer)
{
	// Clear Screen 
	SDL_SetRenderDrawColor(p_renderer, 255, 255, 255, 255);
	SDL_RenderClear(p_renderer);
	
	// Draw wall
	SDL_SetRenderDrawColor(p_renderer, 0, 0, 255, 255);

	for (int i = 0; i < walls.size(); i++)
	{
		walls[i].Draw(p_renderer, cameraPtr);
	}
}