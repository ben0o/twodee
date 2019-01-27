#include "AIInputComponent.hpp"
#include "player.hpp"

void AIInputComponent::Input(SDL_Event& event, Player& player)
{

}

void AIInputComponent::Update(Player& player)
{
	glm::vec2 currentPos = player.GetPosition();
	glm::vec2 newVelocity = player.GetVelocity();
	
	if (currentPos.x < targetA && (newVelocity.x == 0))
	{	
		newVelocity.x += PLAYER_VEL;
	}
	if (currentPos.x >= targetA && (newVelocity.x != 0))
	{
		newVelocity.x = 0;
		newVelocity.x -= PLAYER_VEL;
	}
	if (currentPos.x <= targetB && (newVelocity.x != 0))
	{
		newVelocity.x = 0;
		newVelocity.x += PLAYER_VEL;
	}

	player.SetVelocity(newVelocity);
}