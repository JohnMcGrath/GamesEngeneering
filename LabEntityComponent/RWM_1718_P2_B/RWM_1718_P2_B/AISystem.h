#pragma once
#include "Entity.h"

class AISystem
{
	std::vector<Entity*> entities;

public:
	void addEntity(Entity* e) { entities.push_back(e); }
	void update() 
	{
		std::cout << "AISystem Update" << std::endl;
		for (std::vector<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it)
		{
			std::cout << "Run through ai components" << std::endl;
		}
	}
};
