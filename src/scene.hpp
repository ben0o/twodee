#ifndef SCENE_H
#define SCENE_H

#include "structs.hpp"
#include "Shape.hpp"
#include "player.hpp"
#include "door.hpp"
#include "button.hpp"
#include <SDL2/SDL.h>
#include <vector>
#include <iostream>

class Scene
{
	public:
		Scene();
		Scene(Player *player);
		~Scene();

		void CreateRectangle(int x, int y, int h, int w);
		void CreateDoor(int x, int y, std::string name, bool open);
		void CreateButton(int x, int y, std::string target);

		int GetLevelWidth();
		int GetLevelHeight();

		std::vector<Shape> GetWalls();
		std::vector<Door> GetDoors();
		std::vector<Button> GetButtons();

		void Input(SDL_Event &event);
		void Update(double deltaTime);
		void Draw(SDL_Renderer* p_renderer);

private:
	// Vector of shapes, created using SDL functions.
	std::vector<Shape> walls;
	std::vector<Door> doors;
	std::vector<Button> buttons;

	// Level Size
	int WORLD_WIDTH;
	int WORLD_HEIGHT;

	// Player and camera pointers
	Player *playerPtr;
	Camera Camera;
};

#endif