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
	currScene = new Scene();

	currScene->CreateRectangle(300, 40, 400, 40);
	currScene->CreateRectangle(500, 600, 40, 400);

	currScene->CreateRectangle(0, 0, 768, 10); // Left wall
	currScene->CreateRectangle(1014, 0, 768, 10); // Right wall
	currScene->CreateRectangle(10, 0, 10, 1014); // Top wall
	currScene->CreateRectangle(10, 758, 10, 1014); // Bottom wall

	newPlayer.LoadPlayerSprite(renderer, "../images/playerSprites.png");

	camera = { (int)newPlayer.GetCenterX(), (int)newPlayer.GetCenterY(), SCREEN_WIDTH, SCREEN_HEIGHT };
}
void ControllerGame::SetInput(SDL_Event &event)
{
	//std::cout << "SetInput function called." << std::endl;
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
	}
}
void ControllerGame::Update(double deltaTime)
{
	newPlayer.Update(deltaTime);
	//currScene->Update(camera.x, camera.y);
}
void ControllerGame::Draw(SDL_Renderer* p_renderer)
{
	currScene->Draw(p_renderer);
	newPlayer.Draw(renderer);

	// Draw the scene and the player.
	SDL_RenderPresent(p_renderer);
}
void ControllerGame::DeleteAssets()
{
	
}