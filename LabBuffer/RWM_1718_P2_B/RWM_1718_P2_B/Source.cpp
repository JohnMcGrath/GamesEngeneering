#include <iostream>
using namespace std;
#include "Game.h"

struct item
{
	int id = 1;
};

std::vector<item> buffer;

int front = 0, rear = 0;
int bufferSize = 10;
int emptySem = 10;
int full = 0;

int muteP = 1;
int muteC = 1;

item protoItem;

int result;

void Producer();
void Consumer();

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

void Producer()
{
	while (true)
	{
		std::cout << "Produced Producer Item" << std::endl;

		protoItem = item();
		protoItem.id = rand() % 100;

		P(emptySem);

		P(muteP);

		std::cout << "Added Producer Item" << std::endl;
		buffer.push_back(protoItem);

		V(muteP);

		V(full);
	}
}

void Consumer()
{
	while (true)
	{
		P(full);

		P(muteC);

		//Checks the next one in queue
		result = buffer.at(front).id;

		front = (front + 1) % bufferSize;
		std::cout << "Result ID is; " << result << std::endl;

		V(muteC);

		V(emptySem);
	}
}

int main(int argc, char *argv[])
{
	std::thread p(Producer);
	std::thread c(Consumer);

	while (true)
	{

	}

	return 0;
}