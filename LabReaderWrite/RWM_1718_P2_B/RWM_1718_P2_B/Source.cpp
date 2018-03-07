#include <iostream>
#include <vector>
#include <thread>

using namespace std;

struct item
{
	//Random number in eachone
	int id = rand() % 100;
};

std::vector<item> database;

int numOfreaders = 0;

int muteW = 1;
int muteR = 1;

item protoItem;

int result;

void Writer();
void Reader();

void V(int & semaphore)
{
	semaphore++;
}

void P(int & semaphore)
{
	while (semaphore <= 0)
	{
		//Waiting for access
	}

	semaphore--;
}

void Writer()
{
	while (true)
	{
		//Create Item
		protoItem = item();

		//Wait for access
		P(muteW);

		database.push_back(protoItem);
		std::cout << "Wrote Item to Database" << std::endl;

		//Close access
		V(muteW);
	}
}

void Reader()
{
	while (true)
	{
		P(muteR);

		numOfreaders++;

		//Lock out writers if there's a reader
		if (numOfreaders == 1)
		{
			P(muteW);
		}
		
		V(muteR);

		result = database.at(rand() % database.size()).id;
		std::cout << "Reading Data Base: Id; " << result << std::endl;

		P(muteR);

		numOfreaders--;

		//if last, release
		if (numOfreaders == 0)
		{
			V(muteW);
		}
		V(muteR);
	}
}

int main(int argc, char *argv[])
{
	std::thread w(Writer);
	std::thread c(Reader);

	while (true)
	{

	}

	return 0;
}