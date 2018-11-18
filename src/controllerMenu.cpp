#include "controllerMenu.hpp"

ControllerMenu::ControllerMenu()
{
}

ControllerMenu::~ControllerMenu()
{
}
void ControllerMenu::SetInput(SDL_Event &events)
{
}
void ControllerMenu::Update(double deltaTime)
{
	//Nothing here yet so let's drop out of the menu and have the game controller take over
	bActive = false;
}
void ControllerMenu::Draw(SDL_Renderer* p_renderer)
{
}
void ControllerMenu::LoadScene(std::string)
{
}
void ControllerMenu::DeleteAssets()
{
}