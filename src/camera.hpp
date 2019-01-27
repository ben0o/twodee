#ifndef CAMERA_H
#define CAMERA_H

#include <SDL2/SDL.h>
#include <iostream>
#include "../include/glm/vec2.hpp"

class Camera
{
public:
	
	Camera(SDL_Rect cameraBounds, int levelWidth, int levelHeight) : camera(cameraBounds), LEVEL_WIDTH(levelWidth), LEVEL_HEIGHT(levelHeight) {};

	void SetCameraPosition(glm::vec2 pos);
	SDL_Rect GetCameraPosition();

private:
	int LEVEL_WIDTH, LEVEL_HEIGHT;

	SDL_Rect camera;
};

#endif