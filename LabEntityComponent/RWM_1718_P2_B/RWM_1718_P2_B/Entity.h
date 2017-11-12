#pragma once
#include <vector>
#include <iostream>
#include "Component.h"

class Entity 
{
	int id;
public:
	Entity() {};
	void addComponent();
	void removeComponent();

	void addComponent(Component *c) { components.push_back(c); }
	std::vector<Component*> getComponents() { return components; }

private:
	std::vector<Component*> components;
};
