#pragma once


class Consumer
{
public:
	void update();
	void sleep();
	void removeFromBuffer(item it);
private:
	bool isAsleep = false;
};
