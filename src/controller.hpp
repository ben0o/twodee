#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <SDL2/SDL.h>
#include <string>

class Controller
{
public:
	Controller();
	~Controller();
	
	void SetForegroundStatus();					//used to switch between controllers
	bool GetForegroundStatus();
	
	virtual void SetInput(SDL_Event &events);
    virtual void Update(float timeStep);
    virtual void Draw(SDL_Renderer*);
    
    virtual void LoadScene(std::string);
    virtual void LoadAssets();
	
	virtual void DeleteAssets();
    
protected:
    bool bActive;
	
};
#endif