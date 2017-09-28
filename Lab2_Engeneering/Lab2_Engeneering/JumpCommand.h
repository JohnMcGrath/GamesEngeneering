#pragma once
#include "Command.h"
#include <iostream>

class JumpCommand : public Command
{
public: 
	void jump() { std::cout << "*jump*" << std::endl; }
	virtual void execute() { jump(); }
};
