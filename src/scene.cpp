#include "scene.hpp"

Scene::Scene()
{
	// Default Constructor
}

Scene::Scene(Player *player, Camera *camera, CollisionManager *cMgr) : WORLD_WIDTH(1600), WORLD_HEIGHT(1500)
{
	//WORLD_WIDTH = 1600;
	//WORLD_HEIGHT = 1500;

	playerPtr = player;
	cameraPtr = camera;
	camera->SetCameraBounds(WORLD_WIDTH, WORLD_HEIGHT);

	collisionMgr = cMgr;
	collisionMgr->SetCurrSceneCollisions(&walls, &doors, &buttons, WORLD_WIDTH, WORLD_HEIGHT);

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

void Scene::CreateDoor(int x, int y, std::string name, bool open)
{
	Door newDoor;
	newDoor.CreateDoor(x, y, name, open);
	doors.push_back(newDoor);
}

void Scene::CreateButton(int x, int y, std::string target)
{
	Button newButton;
	newButton.CreateButton(x, y, target);
	buttons.push_back(newButton);
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

std::vector<Door> Scene::GetDoors()
{
	return doors;
}

std::vector<Button> Scene::GetButtons()
{
	return buttons;
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

	for (int i = 0; i < doors.size(); i++)
	{
		doors[i].Draw(p_renderer, cameraPtr);
	}

	for (int i = 0; i < buttons.size(); i++)
	{
		buttons[i].Draw(p_renderer, cameraPtr);
	}
}