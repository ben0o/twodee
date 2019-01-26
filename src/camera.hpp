#ifndef CAMERA_H
#define CAMERA_H

#include <SDL2/SDL.h>
#include <iostream>
#include "../include/glm/vec2.hpp"
#include "structs.hpp"

class Camera
{
public:
	Camera();
	~Camera();
	void CameraInit(glm::vec2 position, int width, int height);
	void SetCameraBounds(int width, int height);
	void SetCameraPosition(glm::vec2 pos);

	SDL_Rect GetCameraPosition();

private:
	int WORLD_WIDTH, WORLD_HEIGHT;

	SDL_Rect camera;
};

#endif