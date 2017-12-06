#pragma once
#include "Component.h"

class RenderComponent : public Component
{
public:
	RenderComponent()
	{
		std::cout << "Render Component Created" << std::endl;
		compID = 2;
	}

	int getIsDrawing() { return isDrawing; }
	void setIsDrawing(bool tf) { isDrawing = tf; }

	//int getID() { return id; }
	
private:
	bool isDrawing;
	int id = 2;
};
