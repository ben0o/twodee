#include "scene.hpp"
#include "Entities/PlayerInputComponent.hpp"
#include "Entities/PlayerGraphicsComponent.hpp"
#include "Entities/PlayerPhysicsComponent.hpp"

Scene::Scene()
{
	// Default Constructor
}

Scene::Scene(Player *player, int levelWidth, int levelHeight, int screenWidth, int screenHeight) : LEVEL_WIDTH(levelWidth), LEVEL_HEIGHT(levelHeight), SCREEN_WIDTH(screenWidth), SCREEN_HEIGHT(screenHeight)
{
	playerPtr = player;
	
	SDL_Rect CamPos = { (int)playerPtr->GetCenter().x - (SCREEN_WIDTH / 2), (int)playerPtr->GetCenter().y - (SCREEN_HEIGHT / 2), SCREEN_WIDTH, SCREEN_HEIGHT };
	camera = new Camera(CamPos, LEVEL_WIDTH, LEVEL_HEIGHT);
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

void Scene::SetAI(Player *AI)
{
	AIPlayerPtr = AI;
}

int Scene::GetLevelWidth()
{
	return LEVEL_WIDTH;
}

int Scene::GetLevelHeight()
{
	return LEVEL_HEIGHT;
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

Camera Scene::GetCamera()
{
	return *camera;
}

void Scene::ResolveCollisions(SDL_Rect bounds, glm::vec2& newPos, glm::vec2 velocity)
{
	bool collisionX, collisionY;
	int playerWidth = bounds.x + bounds.w;
	int playerHeight = bounds.y + bounds.h;

	// -- Test collision with level boundaries --
	if ((newPos.x < 0) || (newPos.x + bounds.w > LEVEL_WIDTH))
		newPos.x -= velocity.x;

	if ((newPos.y < 0) || (newPos.y + bounds.h > LEVEL_HEIGHT))
		newPos.y -= velocity.y;

	// -- Test collision with walls --
	for (std::vector<Shape>::iterator it = walls.begin(); it != walls.end(); ++it)
	{
		SDL_Rect currentRect = it->GetRect();

		// Work out if there's a collision on X or Y.
		collisionX = (newPos.x + bounds.w > currentRect.x) && (currentRect.x + currentRect.w > newPos.x);
		collisionY = (newPos.y + bounds.h > currentRect.y) && (currentRect.y + currentRect.h > newPos.y);

		// If there has been a collision...
		if (collisionX && collisionY)
		{
			int objWidth = currentRect.x + currentRect.w;
			int objHeight = currentRect.y + currentRect.h;

			// Test if collision is from the side
			if (
				(bounds.x <= objWidth || playerWidth >= currentRect.x)
				&& (bounds.y > currentRect.y && bounds.y < objHeight)
				|| (playerHeight >= currentRect.y && playerHeight < objHeight)
				|| (bounds.y <= currentRect.y && playerHeight >= objHeight)
				) // If collision is from the side, move player back to previous position in X-Axis.
				newPos.x -= velocity.x;

			// Test if the collision is from the top or bottom
			if (
				(bounds.y <= objHeight || playerHeight >= currentRect.y)
				&& (bounds.x > currentRect.x && bounds.x < objWidth)
				|| (playerWidth >= currentRect.x && playerWidth < objWidth)
				|| (bounds.x <= currentRect.x && playerWidth >= objWidth)
				) // If collision is from top or bottom, move player back to previous position in y-Axis.
				newPos.y -= velocity.y;
		}
	}

	for (std::vector<Door>::iterator it = doors.begin(); it != doors.end(); ++it)
	{
		if (it->GetOpen() == false)
		{
			SDL_Rect currentRect = it->GetDoorBounds();

			// X-Axis collision
			collisionX = (newPos.x + bounds.w > currentRect.x) && (currentRect.x + currentRect.w > newPos.x);

			// Y-Axis collision
			collisionY = (newPos.y + bounds.h > currentRect.y) && (currentRect.y + currentRect.h > newPos.y);

			if (collisionX && collisionY)
			{
				int objWidth = currentRect.x + currentRect.w;
				int objHeight = currentRect.y + currentRect.h;

				// Test if the collision is from the side
				if (
					(bounds.x <= objWidth || playerWidth >= currentRect.x)
					&& (bounds.y > currentRect.y && bounds.y < objHeight)
					|| (playerHeight >= currentRect.y && playerHeight < objHeight)
					|| (bounds.y <= currentRect.y && playerHeight >= objHeight)
					) // If collision is from the side, move player back to previous position in x-axis.
					newPos.x -= velocity.x;

				// Test if the collision is from the top or bottom
				if (
					(bounds.y <= objHeight || playerHeight >= currentRect.y)
					&& (bounds.x > currentRect.x && bounds.x < objWidth)
					|| (playerWidth >= currentRect.x && playerWidth < objWidth)
					|| (bounds.x <= currentRect.x && playerWidth >= objWidth)
					) // If collision is from top or bottom, move player back to previous position in y-Axis.
					newPos.y -= velocity.y;
			}
		}
	}

	for (std::vector<Button>::iterator it = buttons.begin(); it != buttons.end(); ++it)
	{
		SDL_Rect currentRect = it->GetButtonBounds();

		// X-Axis collision
		collisionX = (newPos.x + bounds.w > currentRect.x) && (currentRect.x + currentRect.w > newPos.x);

		// Y-Axis collision
		collisionY = (newPos.y + bounds.h > currentRect.y) && (currentRect.y + currentRect.h > newPos.y);

		if (collisionX && collisionY)
		{
			//std::cout << "Collision with button." << std::endl;
		}
	}
}

void Scene::Input(SDL_Event &event)
{
	playerPtr->Input(event);
}

void Scene::Update(double deltaTime)
{
	AIPlayerPtr->Update(this, deltaTime);
	playerPtr->Update(this, deltaTime);
	camera->SetCameraPosition(playerPtr->GetCenter());
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
		walls[i].Draw(p_renderer, camera);
	}

	for (int i = 0; i < doors.size(); i++)
	{
		doors[i].Draw(p_renderer, camera);
	}

	for (int i = 0; i < buttons.size(); i++)
	{
		buttons[i].Draw(p_renderer, camera);
	}

	// Draw player
	playerPtr->Draw(p_renderer, *this);

	AIPlayerPtr->Draw(p_renderer, *this);
}