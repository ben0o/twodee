#include "controllerGame.hpp"
#include "Entities/PlayerInputComponent.hpp"
#include "Entities/PlayerGraphicsComponent.hpp"
#include "Entities/PlayerPhysicsComponent.hpp"
#include "Entities/AIInputComponent.hpp"

ControllerGame::ControllerGame()
{
}
ControllerGame::~ControllerGame()
{
}
ControllerGame::ControllerGame(SDL_Renderer* p_renderer, int screenWidth, int screenHeight)
{
	renderer = p_renderer;
	glm::vec2 position = glm::vec2(800, 1050);

	newPlayer = new Player(new PlayerInputComponent(), new PlayerGraphicsComponent(), new PlayerPhysicsComponent(), position);
	currScene = new Scene(newPlayer, 1600, 1500, screenWidth, screenHeight);
	
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
	
	newPlayer->LoadSprite(renderer, "../images/playerSprites.png");

	// Add AI character
	position = glm::vec2(700, 1050);
	AIPlayer = new Player(new AIInputComponent(), new PlayerGraphicsComponent(), new PlayerPhysicsComponent(), position);
	AIPlayer->LoadSprite(renderer, "../images/AISprite.png");
	currScene->SetAI(AIPlayer);
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