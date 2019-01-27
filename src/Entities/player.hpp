#ifndef PLAYER_H
#define PLAYER_H

#include "InputComponent.hpp"
#include "PhysicsComponent.hpp"
#include "GraphicsComponent.hpp"
#include "../camera.hpp"
#include "../../include/glm/vec2.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>

class Scene;

class Player
{
public:
	Player(InputComponent* input, GraphicsComponent* graphics, PhysicsComponent* physics, glm::vec2 position);
	~Player();

	glm::vec2 GetPosition();
	glm::vec2 GetNewPosition();
	glm::vec2 GetSize();
	glm::vec2 GetCenter();
	glm::vec2 GetVelocity();

	void SetPosition(glm::vec2 p);
	void SetNewPosition(glm::vec2 pn);
	void SetVelocity(glm::vec2 v);

	void LoadSprite(SDL_Renderer* p_renderer, std::string imagePath);
	void Input(SDL_Event &event);

	void Update(Scene* currScene, double deltaTime);
	void Draw(SDL_Renderer* p_renderer, Scene& scene);

private:
	glm::vec2 velocity;
	glm::vec2 currentPos;
	glm::vec2 newPosition;
	glm::vec2 size;

	// Components
	InputComponent* pInput;
	PhysicsComponent* pPhysics;
	GraphicsComponent* pGraphics;
};

#endif