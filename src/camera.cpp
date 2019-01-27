#include "camera.hpp"

void Camera::SetCameraPosition(glm::vec2 pos)
{
	camera.x = pos.x - (camera.w / 2);
	camera.y = pos.y - (camera.h / 2);

	// Test if camera goes out of bounds.
	if (camera.x < 0) camera.x = 0;
	if (camera.x > (LEVEL_WIDTH - camera.w)) camera.x = LEVEL_WIDTH - camera.w;
	
	if (camera.y < 0) camera.y = 0;
	if (camera.y > (LEVEL_HEIGHT - camera.h)) camera.y = LEVEL_HEIGHT - camera.h;
}

SDL_Rect Camera::GetCameraPosition()
{
	return camera;
}