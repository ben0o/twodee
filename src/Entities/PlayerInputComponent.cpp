#include "PlayerInputComponent.hpp"
#include "player.hpp"

void PlayerInputComponent::Input(SDL_Event& event, Player& player)
{
	glm::vec2 newVelocity = player.GetVelocity();
	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_w: newVelocity.y -= PLAYER_VEL; break; // Forward
		case SDLK_s: newVelocity.y += PLAYER_VEL; break; // Backward
		case SDLK_a: newVelocity.x -= PLAYER_VEL; break; // Left
		case SDLK_d: newVelocity.x += PLAYER_VEL; break; // Right
		}
		player.SetVelocity(newVelocity);
	}
	if (event.type == SDL_KEYUP)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_w: newVelocity.y += PLAYER_VEL; break;
		case SDLK_s: newVelocity.y -= PLAYER_VEL; break;
		case SDLK_a: newVelocity.x += PLAYER_VEL; break;
		case SDLK_d: newVelocity.x -= PLAYER_VEL; break;
		}
		player.SetVelocity(newVelocity);
	}
}

void PlayerInputComponent::Update(Player& player)
{

}