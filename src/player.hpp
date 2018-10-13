#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>

class Player
{
public:
	enum Direction { FORWARD, BACKWARD, LEFT, RIGHT };

	Player();
	~Player();

	void LoadPlayerSprite(SDL_Renderer* p_renderer, std::string imagePath);
	void UpdateDir(Direction dir, bool enabled);
	void Step(double dt);
	void Draw(SDL_Renderer* p_renderer);

private:
	SDL_Texture* playerSprite;
	SDL_Rect spriteImgCoords, currentPos;

	bool moveDir[4];

};

#endif