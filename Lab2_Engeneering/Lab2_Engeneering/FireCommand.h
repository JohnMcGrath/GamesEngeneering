#pragma once
#include "Command.h"
#include <iostream>

class FireCommand : public Command
{
public:
	void fireGun() { std::cout << "*bang*" << std::endl; }
	virtual void execute() { fireGun(); }
};