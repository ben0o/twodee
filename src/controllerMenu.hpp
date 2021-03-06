#ifndef CONTROLLERMENU_H
#define CONTROLLERMENU_H

#include "controller.hpp"
#include <string>
 
class ControllerMenu : public Controller
{
public:
	ControllerMenu();
	~ControllerMenu();

	virtual void SetInput(SDL_Event &events);
	virtual void Update(double deltaTime);
	virtual void Draw(SDL_Renderer*);
	virtual void LoadScene(std::string);
	virtual void DeleteAssets();
};
#endif