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
void Controller::SetInput(SDL_Event &events)			//virtual
{

}
void Controller::Update(float timeStep)					//virtual
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