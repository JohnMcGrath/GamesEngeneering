#pragma once
#include "Entity.h"

class RenderSystem
{
	std::vector<Entity*> entities;

public:
	void addEntity(Entity* e) { entities.push_back(e); }
	void update() {
		std::cout << "RenderSystem Update" << std::endl;

		for (std::vector<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it)
		{
			std::cout << "Run through render components" << std::endl;
		}
	}
};
