#pragma once
#include "Entity.h"

class ControlSystem
{
	std::vector<Entity*> entities;

public:
	void addEntity(Entity* e) { entities.push_back(e); }
	void update() 
	{
		std::cout << "" << std::endl;
		std::cout << "ControlSystem Update" << std::endl;

		for (std::vector<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it)
		{
			std::cout << "Run Through Control Enties" << std::endl;

			std::vector<Component*> tempVec = (*it)->getComponents();

			for (std::vector<Component*>::iterator tempIt = tempVec.begin(); tempIt != tempVec.end(); ++tempIt)
			{
				if ((*tempIt)->getID() == 0)
				{
					std::cout << "Control Component Update" << std::endl;
				}
			}
		}
	}
};
