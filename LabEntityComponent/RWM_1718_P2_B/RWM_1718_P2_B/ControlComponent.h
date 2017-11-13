#pragma once
#include "Component.h"

class ControlComponent : public Component
{
public:
	ControlComponent() { std::cout << "Control Component Created" << std::endl; }

	int getXPos() { return m_xPos; }
	void setXPos(int x) { m_xPos = x; }

	int getYPos() { return m_yPos; }
	void setYPos(int y) { m_yPos = y; }

	int getID() { return id; }

private:
	int m_xPos = 100;
	int m_yPos = 50;
	int id = 0;
};

