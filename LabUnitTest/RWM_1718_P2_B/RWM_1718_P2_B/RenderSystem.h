#pragma once
#include "Entity.h"
#include "Component.h"

class RenderSystem
{
	std::vector<Entity*> entities;

public:
	bool foundComponent = false;
	void addEntity(Entity* e) { entities.push_back(e); }
	bool getfoundComponent() { return foundComponent; }
	void update()
	{
		std::cout << "" << std::endl;
		std::cout << "RenderSystem Update" << std::endl;

		for (std::vector<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it)
		{
			std::cout << "Run Through Render Entities" << std::endl;

			std::vector<Component*> tempVec = (*it)->getComponents();

			for (std::vector<Component*>::iterator tempIt = tempVec.begin(); tempIt != tempVec.end(); ++tempIt)
			{
				if ((*tempIt)->getID() == 2)
				{
					std::cout << "Render Component Update" << std::endl;
					foundComponent = true;
				}
			}

		}
	}
};
