#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

using namespace std;

struct item
{
	//Random number in each one
	int id = rand() % 100;
};

std::vector<item> database;

int numOfreaders = 0;

std::mutex mutexR;
std::mutex mutexW;

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
		//P(muteW);
		mutexW.lock();

		database.push_back(protoItem);
		std::cout << "Wrote Item to Database" << std::endl;

		//Close access
		mutexW.unlock();
	}
}

void Reader()
{
	while (true)
	{
		//P(muteR);
		mutexR.lock();
		
		numOfreaders++;

		//Lock out writers if there's a reader
		if (numOfreaders == 1)
		{
			mutexW.lock();
			//P(muteW);
		}
		
		//V(muteR);
		mutexR.unlock();

		result = database.at(rand() % database.size()).id;
		std::cout << "Reading Data Base: Id; " << result << std::endl;

	    //P(muteR);
		mutexR.lock();

		numOfreaders--;

		//if last, release
		if (numOfreaders == 0)
		{
			//V(muteW);
			mutexW.unlock();
		}
		//V(muteR);
		mutexR.unlock();
	}
}

int main(int argc, char *argv[])
{
	std::thread w(Writer);
	std::thread c(Reader);

	w.join();
	c.join();

	while (true)
	{
		//Keep the progrmamme running
	}

	return 0;
}