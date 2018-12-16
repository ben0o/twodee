#include "camera.hpp"

Camera::Camera()
{

}

Camera::~Camera()
{

}

void Camera::CameraInit(int cameraX, int cameraY, int width, int height)
{
	camera.x = cameraX;
	camera.y = cameraY;
	camera.w = width;
	camera.h = height;
}
void Camera::SetCameraBounds(int width, int height)
{
	WORLD_WIDTH = width;
	WORLD_HEIGHT = height;
}

void Camera::SetCameraPosition(int x, int y)
{
	camera.x = x - (camera.w / 2);
	camera.y = y - (camera.h / 2);

	// Test if camera goes out of bounds.
	if (camera.x < 0) camera.x = 0;
	if (camera.x > (WORLD_WIDTH - camera.w)) camera.x = WORLD_WIDTH - camera.w;
	
	if (camera.y < 0) camera.y = 0;
	if (camera.y > (WORLD_HEIGHT - camera.h)) camera.y = WORLD_HEIGHT - camera.h;
}

SDL_Rect Camera::GetCameraPosition()
{
	return camera;
}