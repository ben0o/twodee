#ifndef CAMERA_H
#define CAMERA_H

#include <SDL2/SDL.h>
#include <iostream>
#include "structs.hpp"

class Camera
{
public:
	Camera();
	~Camera();
	void CameraInit(int cameraX, int cameraY, int width, int height);
	void SetCameraBounds(int width, int height);
	void SetCameraPosition(int x, int y);

	SDL_Rect GetCameraPosition();

private:
	int WORLD_WIDTH, WORLD_HEIGHT;

	SDL_Rect camera;
};

#endif