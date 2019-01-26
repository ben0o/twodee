#include "controllerGame.hpp"

ControllerGame::ControllerGame()
{
}
ControllerGame::~ControllerGame()
{
}
ControllerGame::ControllerGame(SDL_Renderer* p_renderer)
{
	renderer = p_renderer;
	
	currScene = new Scene(&newPlayer);

	//glm::vec2 cameraPos = glm::vec2(newPlayer.GetCenter().x - (SCREEN_WIDTH / 2), (newPlayer.GetCenter().y - (SCREEN_HEIGHT / 2)));
	//camera.CameraInit(cameraPos, SCREEN_WIDTH, SCREEN_HEIGHT);
	
	currScene->CreateRectangle(300, 40, 400, 40);
	currScene->CreateRectangle(500, 600, 40, 400);
	currScene->CreateRectangle(1000, 200, 200, 40);

	// --- Level Border ---
	currScene->CreateRectangle(0, 0, currScene->GetLevelHeight(), 10); // Left wall
	currScene->CreateRectangle(currScene->GetLevelWidth()-10, 0, currScene->GetLevelHeight(), 10); // Right wall
	currScene->CreateRectangle(10, 0, 10, currScene->GetLevelWidth()-10); // Top wall
	currScene->CreateRectangle(10, currScene->GetLevelHeight()-10, 10, currScene->GetLevelWidth()-10); // Bottom wall
	// --------------------

	currScene->CreateRectangle(10, 890, 10, currScene->GetLevelWidth() / 2);
	currScene->CreateRectangle((currScene->GetLevelWidth() / 2) + 100, 890, 10, (currScene->GetLevelWidth() / 2)-100);

	currScene->CreateDoor(currScene->GetLevelWidth() / 2, 890, "New Door", true);

	currScene->CreateButton((currScene->GetLevelWidth() / 2) - 100, 890, "New Door");
	
	newPlayer.LoadPlayerSprite(renderer, "../images/playerSprites.png");
}
void ControllerGame::SetInput(SDL_Event &event)
{
	currScene->Input(event);
}

void ControllerGame::Update(double deltaTime)
{
	currScene->Update(deltaTime);
}
void ControllerGame::Draw(SDL_Renderer* p_renderer)
{
	currScene->Draw(p_renderer);

	// Draw the scene and the player.
	SDL_RenderPresent(p_renderer);
}