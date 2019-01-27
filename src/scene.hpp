#ifndef SCENE_H
#define SCENE_H

#include "Shape.hpp"
#include "Entities/player.hpp"
#include "door.hpp"
#include "button.hpp"
#include <SDL2/SDL.h>
#include <vector>
#include <iostream>

class Scene
{
	public:
		Scene();
		Scene(Player *player, int levelWidth, int levelHeight, int screenWidth, int screenHeight);
		~Scene();

		void CreateRectangle(int x, int y, int h, int w);
		void CreateDoor(int x, int y, std::string name, bool open);
		void CreateButton(int x, int y, std::string target);

		void SetAI(Player *AI);

		int GetLevelWidth();
		int GetLevelHeight();

		std::vector<Shape> GetWalls();
		std::vector<Door> GetDoors();
		std::vector<Button> GetButtons();

		Camera GetCamera();

		void ResolveCollisions(SDL_Rect bounds, glm::vec2& newPos, glm::vec2 velocity);

		void Input(SDL_Event &event);
		void Update(double deltaTime);
		void Draw(SDL_Renderer* p_renderer);

private:
	// Vector of shapes, created using SDL functions.
	std::vector<Shape> walls;
	std::vector<Door> doors;
	std::vector<Button> buttons;

	// Level Size
	int LEVEL_WIDTH;
	int LEVEL_HEIGHT;

	// Screen Size
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;

	// Player and camera pointers
	Player *playerPtr;
	Camera *camera;

	Player *AIPlayerPtr;
};

#endif