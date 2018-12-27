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
	
	currScene = new Scene(&newPlayer, &camera, &collisionMgr);

	int cameraX = (int)(newPlayer.GetCenterX() - (SCREEN_WIDTH / 2));
	int cameraY = (int)(newPlayer.GetCenterY() - (SCREEN_HEIGHT / 2));

	camera.CameraInit(cameraX, cameraY, SCREEN_WIDTH, SCREEN_HEIGHT);

	currScene->CreateRectangle(300, 40, 400, 40);
	currScene->CreateRectangle(500, 600, 40, 400);
	currScene->CreateRectangle(1000, 200, 200, 40);

	// --- Level Border ---
	currScene->CreateRectangle(0, 0, currScene->GetLevelHeight(), 10); // Left wall
	currScene->CreateRectangle(currScene->GetLevelWidth()-10, 0, currScene->GetLevelHeight(), 10); // Right wall
	currScene->CreateRectangle(10, 0, 10, currScene->GetLevelWidth()-10); // Top wall
	currScene->CreateRectangle(10, currScene->GetLevelHeight()-10, 10, currScene->GetLevelWidth()-10); // Bottom wall
	// --------------------

	newPlayer.LoadPlayerSprite(renderer, "../images/playerSprites.png");
}
void ControllerGame::SetInput(SDL_Event &event)
{
	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
			case SDLK_w: newPlayer.SetDirection(Player::FORWARD, true); break;
			case SDLK_s: newPlayer.SetDirection(Player::BACKWARD, true); break;
			case SDLK_a: newPlayer.SetDirection(Player::LEFT, true); break;
			case SDLK_d: newPlayer.SetDirection(Player::RIGHT, true); break;
		};
	}
	if (event.type == SDL_KEYUP)
	{
		switch (event.key.keysym.sym)
		{
			case SDLK_w: newPlayer.SetDirection(Player::FORWARD, false); break;
			case SDLK_s: newPlayer.SetDirection(Player::BACKWARD, false); break;
			case SDLK_a: newPlayer.SetDirection(Player::LEFT, false); break;
			case SDLK_d: newPlayer.SetDirection(Player::RIGHT, false); break;
		};
		//std::cout << "Walls on screen: " << collisionMgr.GetCurrSceneCollisions().size() << std::endl;
	}
}

void ControllerGame::Update(double deltaTime)
{
	// -----
	// 1. Calculate new player position (Player class).
	// 2. Check for collision (collision detection done in CollisionManager, called from Player class).
	// 3. If collision is detected, reset player position.
	// 4. If no collision is detected, apply new player and camera positions.
	// -----

	//collisionMgr.UpdateCollidableObjectsOnScreen();
	newPlayer.CalculateNewPosition(deltaTime);
	newPlayer.Update(&camera);
}
void ControllerGame::Draw(SDL_Renderer* p_renderer)
{
	currScene->Draw(p_renderer);
	newPlayer.Draw(renderer, &camera);

	// Draw the scene and the player.
	SDL_RenderPresent(p_renderer);
}
void ControllerGame::DeleteAssets()
{
	
}