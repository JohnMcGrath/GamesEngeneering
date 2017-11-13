#pragma once
#include "Component.h"

class RenderComponent : public Component
{
public:
	RenderComponent() { std::cout << "Render Component Created" << std::endl; }

	int getIsDrawing() { return isDrawing; }
	void setIsDrawing(bool tf) { isDrawing = tf; }

private:
	bool isDrawing;
};
