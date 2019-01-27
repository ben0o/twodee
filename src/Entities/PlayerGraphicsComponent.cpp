#include "PlayerGraphicsComponent.hpp"
#include "player.hpp"
#include "../scene.hpp"

void PlayerGraphicsComponent::LoadSprite(SDL_Renderer* p_renderer, std::string imagePath)
{
	//Load PNG file
	SDL_Surface* loadedSurface = IMG_Load(imagePath.c_str());
	if (loadedSurface == NULL)
		std::cout << "Unable to load image " << imagePath << std::endl;
	else
	{
		// Convert surface to texture
		sprite = SDL_CreateTextureFromSurface(p_renderer, loadedSurface);

		// Delete surface
		SDL_FreeSurface(loadedSurface);

		// Set sprite coordinates on image file.
		forwardSprite = { 0, 0, 30, 48 }; // X, Y, W, H
		leftSprite = { 0, 48, 30, 48 };
		rightSprite = { 0, 96, 30, 48 };
		backSprite = { 0, 144, 30, 48 };
	}
}

void PlayerGraphicsComponent::Draw(SDL_Renderer* p_renderer, Player& player, Scene& scene)
{
	SDL_Rect newPos = { (int)player.GetPosition().x - scene.GetCamera().GetCameraPosition().x, (int)player.GetPosition().y - scene.GetCamera().GetCameraPosition().y, (int)player.GetSize().x, (int)player.GetSize().y }; //  X, Y, W, H

	if (player.GetVelocity().x < 0)
		SDL_RenderCopy(p_renderer, sprite, &leftSprite, &newPos);
	else if (player.GetVelocity().x > 0)
		SDL_RenderCopy(p_renderer, sprite, &rightSprite, &newPos);

	else if (player.GetVelocity().y > 0)
		SDL_RenderCopy(p_renderer, sprite, &forwardSprite, &newPos);
	else if (player.GetVelocity().y < 0)
		SDL_RenderCopy(p_renderer, sprite, &backSprite, &newPos);

	else
		SDL_RenderCopy(p_renderer, sprite, &forwardSprite, &newPos);
}