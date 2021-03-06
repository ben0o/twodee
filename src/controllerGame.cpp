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
	newTexture = NULL;

	currScene->CreateRectangle(300, 40, 400, 40);
	currScene->CreateRectangle(500, 600, 40, 400);

	newPlayer.LoadPlayerSprite(renderer, "../images/playerSprites.png");
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
	// Delete textures
	SDL_DestroyTexture(newTexture);
}