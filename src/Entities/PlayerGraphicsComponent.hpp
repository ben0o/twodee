#ifndef PLAYERGRAPHICSCOMPONENT_H
#define PLAYERGRAPHICSCOMPONENT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>
#include "GraphicsComponent.hpp"

class Player;
class Scene;

class PlayerGraphicsComponent : public GraphicsComponent
{
public:
	void LoadSprite(SDL_Renderer* p_renderer, std::string imagePath);
	void Draw(SDL_Renderer* p_renderer, Player& player, Scene& scene);

private:
	SDL_Texture * sprite;
	SDL_Rect forwardSprite, leftSprite, rightSprite, backSprite;

};

#endif