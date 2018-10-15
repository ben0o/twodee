#include "controllerMenu.hpp"

ControllerMenu::ControllerMenu(Settings* _settings)
{
	//Passed settings initially loaded from file on start up
	p_settings = _settings;
}
ControllerMenu::~ControllerMenu()
{
}
void ControllerMenu::SetInput(double dt)
{
}
void ControllerMenu::Update(double dt)
{
	//Nothing here yet so let's drop out of the menu and have the game controller take over
	p_settings->level = "one";
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