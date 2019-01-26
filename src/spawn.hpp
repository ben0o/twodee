#ifndef SPAWN_H
#define SPAWN_H

class Spawn
{
public:
	void SetPosition(int x, int y);
	int GetPosX();
	int GetPosY();
private:
	int x, int y;
};

#endif