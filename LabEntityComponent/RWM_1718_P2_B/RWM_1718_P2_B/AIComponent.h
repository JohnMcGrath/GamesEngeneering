#pragma once
#include "Component.h"

class AIComponent : public Component
{
public:
	AIComponent() { std::cout << "AI Component Created" << std::endl; }

	bool getIsIdle() { return isIdle; }
	void setIsIdle(bool tf) { isIdle = tf; }
	bool getIsHostile() { return isHostile; }
	void setIsHostile(bool tf) { isHostile = tf; }
	bool getIsWalking() { return isWalking; }
	void setIsWalking(bool tf) { isWalking = tf; }

private:
	bool isIdle;
	bool isHostile;
	bool isWalking;
};
