#ifndef GRAPHICSCOMPONENT_H
#define GRAPHICSCOMPONENT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>

class Player;
class Scene;

class GraphicsComponent
{
public:
	virtual ~GraphicsComponent() {};
	virtual void LoadSprite(SDL_Renderer* p_renderer, std::string imagePath) = 0;
	virtual void Draw(SDL_Renderer* p_renderer, Player& player, Scene& scene) = 0;

};

#endif