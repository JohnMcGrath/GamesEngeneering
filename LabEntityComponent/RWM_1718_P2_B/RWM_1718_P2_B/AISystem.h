#pragma once
#include "Entity.h"

class AISystem
{
	std::vector<Entity*> entities;

public:
	void addEntity(Entity* e) { entities.push_back(e); }
	void update() 
	{
		std::cout << "" << std::endl;
		std::cout << "AISystem Update" << std::endl;
		for (std::vector<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it)
		{
			std::cout << "Run Through AI Entities" << std::endl;

			std::vector<Component*> tempVec = (*it)->getComponents();

			for (std::vector<Component*>::iterator tempIt = tempVec.begin(); tempIt != tempVec.end(); ++tempIt)
			{
				if ((*tempIt)->getID() == 1)
				{
					std::cout << "AI Component Update" << std::endl;
				}
			}
		}
	}
};
