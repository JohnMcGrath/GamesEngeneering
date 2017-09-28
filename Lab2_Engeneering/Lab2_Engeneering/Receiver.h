#pragma once
#include "Command.h"

class Receiver 
{
public :
	Receiver(std::string action)
	{
		if (action == "*fire*")
		{
			std::cout << "bang bang ";
		}
	}
};
