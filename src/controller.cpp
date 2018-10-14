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
void Controller::Draw(SDL_Renderer* p_renderer)		//virtual
{
}
void Controller::SetInput(double dt)			//virtual
{

}
void Controller::Update(double dt)					//virtual
{
}
void Controller::LoadScene(std::string strFileName)	//virtual
{
}
void Controller::LoadAssets()						//virtual
{
}
void Controller::DeleteAssets()						//virtual
{
}