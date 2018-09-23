#include "controller.hpp"

Controller::Controller()
{
}
Controller::~Controller()
{
}
void Controller::SetForegroundStatus()
{
	bActive = true;
}
bool Controller::GetForegroundStatus()
{
	return bActive;
}
void Controller::Draw(SDL_Renderer* p_renderer)							//virtual
{
}
void Controller::Update(double dt)				//virtual
{
	//Nothing here yet so let's drop out of the menu and have the game controller take over
	bActive = false;
}
void Controller::LoadScene(std::string strFileName)	//virtual
{
}
void Controller::LoadAssets()
{
}