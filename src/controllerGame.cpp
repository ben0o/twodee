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
void ControllerGame::SetInput(double dt)
{
	SDL_PumpEvents();
	const Uint8 *keyStates = SDL_GetKeyboardState(NULL);
	if (keyStates[SDL_SCANCODE_W])
		newPlayer.SetDirection(Player::FORWARD, true);
	else
		newPlayer.SetDirection(Player::FORWARD, false);
	if (keyStates[SDL_SCANCODE_A])
		newPlayer.SetDirection(Player::LEFT, true);
	else
		newPlayer.SetDirection(Player::LEFT, false);
	if (keyStates[SDL_SCANCODE_S])
		newPlayer.SetDirection(Player::BACKWARD, true);
	else
		newPlayer.SetDirection(Player::BACKWARD, false);
	if (keyStates[SDL_SCANCODE_D])
		newPlayer.SetDirection(Player::RIGHT, true);
	else
		newPlayer.SetDirection(Player::RIGHT, false);
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