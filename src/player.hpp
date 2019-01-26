#ifndef PLAYER_H
#define PLAYER_H

#include "structs.hpp"
#include "camera.hpp"
#include "../include/glm/vec2.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>

class Scene;
class Player
{
public:
	Player();
	~Player();

	glm::vec2 GetPosition();
	glm::vec2 GetCenter();
	glm::vec2 GetVelocity();

	void LoadPlayerSprite(SDL_Renderer* p_renderer, std::string imagePath);
	void Input(SDL_Event &event);

	void Update(Camera* camera, Scene* currScene, double deltaTime);
	void Draw(SDL_Renderer* p_renderer, Camera* camera);

private:
	SDL_Texture* playerSprite;
	SDL_Rect forwardSprite, leftSprite, rightSprite, backSprite;
	SDL_Rect newCamera; // Buffer camera

	// Maximum player velocity (walking speed)
	const float PLAYER_VEL = 0.2;

	glm::vec2 playerSize;

	glm::vec2 velocity;
	glm::vec2 currentPos;
	glm::vec2 newPosition;
};

#endif