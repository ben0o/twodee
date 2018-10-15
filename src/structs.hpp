#ifndef STRUCTS_H
#define STRUCTS_H

#include <string>


struct Settings
{
	std::string level; //Used by menu controller to start a new game
	
	//Defaults
	Settings()
	{
		level = "";		
	}
};

#endif