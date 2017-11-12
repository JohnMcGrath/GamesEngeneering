#pragma once
#include "Component.h"

class HealthComponent : public Component
{
public:
	HealthComponent() { std::cout << "Health System Created" << std::endl; }

	int getHealth() { return m_health; }
	void setHealth(int health) { m_health = health; }

private:
	int m_health = 100;
};
