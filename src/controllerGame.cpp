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
	
	currScene = new Scene(&newPlayer, &camera);

	//int cameraX = (int)((600 + 30/2) - (SCREEN_WIDTH / 2));
	int cameraX = (int)(newPlayer.GetCenterX() - (SCREEN_WIDTH / 2));
	int cameraY = (int)(newPlayer.GetCenterY() - (SCREEN_HEIGHT / 2));

	//if (cameraX < 0) cameraX = 0;
	//if (cameraY < 0) cameraY = 0;
	camera = { cameraX, cameraY, SCREEN_WIDTH, SCREEN_HEIGHT };

	currScene->CreateRectangle(300, 40, 400, 40);
	currScene->CreateRectangle(500, 600, 40, 400);

	// --- Level Border ---
	currScene->CreateRectangle(0, 0, WORLD_HEIGHT, 10); // Left wall
	currScene->CreateRectangle(WORLD_WIDTH-10, 0, WORLD_HEIGHT, 10); // Right wall
	currScene->CreateRectangle(10, 0, 10, WORLD_WIDTH-10); // Top wall
	currScene->CreateRectangle(10, WORLD_HEIGHT-10, 10, WORLD_WIDTH-10); // Bottom wall
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
		std::cout << "camera X: " << camera.x << std::endl;
		std::cout << "Player Center X: " << newPlayer.GetCenterX() << std::endl;
		std::cout << "WORLD_WIDTH - camera.w: " << WORLD_WIDTH - camera.w << std::endl;
	}
}
void ControllerGame::Update(double deltaTime)
{
	newPlayer.Update(deltaTime, &camera);
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