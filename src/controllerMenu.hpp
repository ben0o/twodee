#ifndef CONTROLLERMENU_H
#define CONTROLLERMENU_H

#include "controller.hpp"
#include <string>
 
class ControllerMenu : public Controller
{
public:
	ControllerMenu();
	~ControllerMenu();

	virtual void Update(double);
	virtual void Draw(SDL_Renderer*);
	virtual void LoadScene(std::string);	
};
#endif