#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <SDL2/SDL.h>
#include <string>
#include "structs.hpp"

class Controller
{
public:
	Controller();
	~Controller();
	
	void SetForegroundStatus();					//used to switch between controllers
	bool GetForegroundStatus();
	
	virtual void SetInput(double dt);
    virtual void Update(double dt);
    virtual void Draw(SDL_Renderer*);
    
    virtual void LoadScene(std::string);
    virtual void LoadAssets() {}
	
	virtual void DeleteAssets() {}
	virtual void CompareSettings(Settings*) {}
    
protected:
    bool bActive;
	
};
#endif