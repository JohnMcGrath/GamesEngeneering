#pragma once
#include "Consumer.h"


class Producer
{
public:
	void update();
	item produce();
	void addToBuffer(item it);
	void wakeUp();
private:
	int itemCount = 0;
};