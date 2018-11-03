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

	newPlayer.LoadPlayerSprite(renderer, "../images/playerSprites.png");
}
void ControllerGame::SetInput(SDL_Event &event)
{
	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
			case SDLK_w:
			{
				newPlayer.SetDirection(Player::FORWARD, true); break;
			}
			case SDLK_s:
			{
				newPlayer.SetDirection(Player::BACKWARD, true); break;
			}
			case SDLK_a:
			{
				newPlayer.SetDirection(Player::LEFT, true); break;
			}
			case SDLK_d:
			{
				newPlayer.SetDirection(Player::RIGHT, true); break;
			}
		};
	}
	if (event.type == SDL_KEYUP)
	{
		switch (event.key.keysym.sym)
		{
			case SDLK_w: 
			{
				newPlayer.SetDirection(Player::FORWARD, false); break;
			}
			case SDLK_s:
			{
				newPlayer.SetDirection(Player::BACKWARD, false); break;
			}
			case SDLK_a:
			{
				newPlayer.SetDirection(Player::LEFT, false); break;
			}
			case SDLK_d:
			{
				newPlayer.SetDirection(Player::RIGHT, false); break;
			}
		};
	}
}
void ControllerGame::Update(float timeStep)
{
	newPlayer.Update(timeStep);
}
void ControllerGame::Draw(SDL_Renderer* p_renderer)
{
	newPlayer.Draw(renderer);
}
void ControllerGame::DeleteAssets()
{
	// Delete textures
	SDL_DestroyTexture(newTexture);
}