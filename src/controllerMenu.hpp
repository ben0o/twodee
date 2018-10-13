#ifndef CONTROLLERMENU_H
#define CONTROLLERMENU_H

#include "controller.hpp"
#include <string>
 
class ControllerMenu : public Controller
{
public:
	ControllerMenu();
	~ControllerMenu();

	virtual void SetInput(SDL_Event &event);
	virtual void Update(double dt);
	virtual void Draw(SDL_Renderer*);
	virtual void LoadScene(std::string);
	virtual void DeleteAssets();
};
#endif