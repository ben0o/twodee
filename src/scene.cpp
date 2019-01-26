#include "scene.hpp"

Scene::Scene()
{
	// Default Constructor
}

Scene::Scene(Player *player) : WORLD_WIDTH(1600), WORLD_HEIGHT(1500)
{
	//WORLD_WIDTH = 1600;
	//WORLD_HEIGHT = 1500;

	playerPtr = player;
	
	glm::vec2 cameraPos = glm::vec2(playerPtr->GetCenter().x - (SCREEN_WIDTH / 2), (playerPtr->GetCenter().y - (SCREEN_HEIGHT / 2)));
	Camera.CameraInit(cameraPos, SCREEN_WIDTH, SCREEN_HEIGHT);
	Camera.SetCameraBounds(WORLD_WIDTH, WORLD_HEIGHT);
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

void Scene::Input(SDL_Event &event)
{
	playerPtr->Input(event);
}

void Scene::Update(double deltaTime)
{
	playerPtr->Update(&Camera, this, deltaTime);
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
		walls[i].Draw(p_renderer, &Camera);
	}

	for (int i = 0; i < doors.size(); i++)
	{
		doors[i].Draw(p_renderer, &Camera);
	}

	for (int i = 0; i < buttons.size(); i++)
	{
		buttons[i].Draw(p_renderer, &Camera);
	}

	// Draw player
	playerPtr->Draw(p_renderer, &Camera);
}