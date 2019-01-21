#include "button.hpp"

Button::Button()
{

}

Button::~Button()
{

}

void Button::CreateButton(int x, int y, std::string doorTarget)
{
	bBorder.x = x;
	bBorder.y = y;
	bBorder.h = 10;
	bBorder.w = 10;

	bSwitch.x = bBorder.x + (bBorder.w / 8);
	bSwitch.y = bBorder.y + (bBorder.h / 8);
	bSwitch.h = bBorder.h - ((bBorder.h / 8)*2);
	bSwitch.w = bBorder.w - ((bBorder.w / 8)*2);
	doorTargetName = doorTarget;

	bBounds.x = bBorder.x - (bBorder.w / 2);
	bBounds.y = bBorder.y - (bBorder.h / 2);
	bBounds.h = bBorder.h + ((bBorder.h / 2)*2);
	bBounds.w = bBorder.w + ((bBorder.w / 2)*2);
}

SDL_Rect Button::GetButtonBounds()
{
	return bBounds;
}

std::string Button::GetDoorTarget()
{
	return doorTargetName;
}

void Button::Draw(SDL_Renderer* p_renderer, Camera* camera)
{
	SDL_Rect ScreenPos;
	ScreenPos.x = bBorder.x - camera->GetCameraPosition().x;
	ScreenPos.y = bBorder.y - camera->GetCameraPosition().y;
	ScreenPos.w = bBorder.w;
	ScreenPos.h = bBorder.h;

	SDL_Rect ScreenPosSwitch;
	ScreenPosSwitch.x = bSwitch.x - camera->GetCameraPosition().x;
	ScreenPosSwitch.y = bSwitch.y - camera->GetCameraPosition().y;
	ScreenPosSwitch.w = bSwitch.w;
	ScreenPosSwitch.h = bSwitch.h;

	SDL_Rect ScreenPosBounds;
	ScreenPosBounds.x = bBounds.x - camera->GetCameraPosition().x;
	ScreenPosBounds.y = bBounds.y - camera->GetCameraPosition().y;
	ScreenPosBounds.w = bBounds.w;
	ScreenPosBounds.h = bBounds.h;

	SDL_SetRenderDrawColor(p_renderer, 0, 0, 0, 0);
	SDL_RenderFillRect(p_renderer, &ScreenPos);

	SDL_SetRenderDrawColor(p_renderer, 255, 0, 0, 0);
	SDL_RenderFillRect(p_renderer, &ScreenPosSwitch);

	//SDL_SetRenderDrawColor(p_renderer, 0, 0, 0, 0);
	//SDL_RenderDrawRect(p_renderer, &ScreenPosBounds);
}