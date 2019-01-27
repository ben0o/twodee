#include "PlayerPhysicsComponent.hpp"
#include "player.hpp"
#include "../scene.hpp"

void PlayerPhysicsComponent::Update(Scene& scene, Player& player, double deltaTime)
{
	glm::vec2 newPosition = player.GetNewPosition();
	newPosition.x += player.GetVelocity().x * deltaTime;
	newPosition.y += player.GetVelocity().y * deltaTime;

	SDL_Rect playerBounds = { (int)player.GetPosition().x, (int)player.GetPosition().y, (int)player.GetSize().x, (int)player.GetSize().y };

	scene.ResolveCollisions(playerBounds, newPosition, player.GetVelocity());

	player.SetNewPosition(newPosition);
	player.SetPosition(newPosition);
}