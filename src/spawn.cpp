#include "spawn.hpp"

void Spawn::SetPosition(int x, int y)
{
	this.x = x;
	this.y = y;
}

int Spawn::GetPosX()
{
	return x;
}

int Spawn::GetPosY()
{
	return y;
}