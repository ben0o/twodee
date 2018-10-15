#ifndef CONTROLLERMENU_H
#define CONTROLLERMENU_H

#include "controller.hpp"
#include <string>
#include "structs.hpp"
 
class ControllerMenu : public Controller
{
public:
	ControllerMenu(Settings*);
	~ControllerMenu();

	virtual void SetInput(double dt);
	virtual void Update(double dt);
	virtual void Draw(SDL_Renderer*);
	virtual void LoadScene(std::string);
	virtual void DeleteAssets();
	virtual void CompareSettings(Settings*) {}
	private:
	Settings* p_settings;
};
#endif