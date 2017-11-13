#pragma once
#include <vector>
#include <iostream>
#include "Component.h"

class Entity 
{
	int id;
public:
	Entity() {};

	void addComponent(Component *c) { components.push_back(c); }

	void removeComponent(int idToRemvoe)
	{
		for (std::vector<Component*>::iterator it = components.begin(); it != components.end(); ++it)
		{
			//if the id equals the past one
		}
	}
	std::vector<Component*> getComponents() { return components; }

private:
	std::vector<Component*> components;
};
