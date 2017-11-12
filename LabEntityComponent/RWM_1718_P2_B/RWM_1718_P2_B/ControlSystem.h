#pragma once
#include "Component.h"

class ControlComponent : public Component
{
public:
	ControlComponent() { std::cout << "Control System Created" << std::endl; }

	int getXPos() { return m_xPos; }
	void setXPos(int x) { m_xPos = x; }

	int getYPos() { return m_yPos; }
	void setYPos(int y) { m_yPos = y; }

private:
	int m_xPos = 100;
	int m_yPos = 50;
};

