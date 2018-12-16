#ifndef STRUCTS_H
#define STRUCTS_H

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

//const int WORLD_WIDTH = 1600;
//const int WORLD_HEIGHT = 900;

struct BoundingBox {
	float top;
	float bottom;
	float left;
	float right;
};

#endif