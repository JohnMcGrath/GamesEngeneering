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

void Vmutex(std::mutex & mutex)
{
	mutex.lock();
}

void Pmutex(std::mutex & mutex)
{
	while (numOfreaders < 0)
	{
		//wait
	}
	mutex.unlock();
}

void Writer()
{
	while (true)
	{
		//Create Item
		protoItem = item();

		//Wait for access
		P(muteW); //Using int to represent semaphore
		//mutexW.unlock(); //Convert to mutexs
		//mutexW.lock(); //Flipped mutexs
		//Pmutex(mutexW); //Attempting to convert P to use mutex

		database.push_back(protoItem);
		std::cout << "Wrote Item to Database" << std::endl;

		//Close access
		V(muteW);
		//mutexW.lock();
		//mutexW.unlock();
		//Vmutex(mutexR);
	}
}

void Reader()
{
	while (true)
	{
		P(muteR);
		//mutexR.unlock();
		//mutexR.lock();
		//Pmutex(mutexR);
		
		numOfreaders++;
		//numOfreaders--;

		//Lock out writers if there's a reader
		if (numOfreaders == 1)
		{
			P(muteW);
			//mutexW.unlock();
			//mutexW.lock();
			//Pmutex(mutexW);
		}
		
		V(muteR);
		//mutexR.lock();
		//mutexR.unlock();
		//Vmutex(mutexR);

		if (database.size() != 0)
		{
			result = database.at(rand() % database.size()).id;
			std::cout << "Reading Data Base: Id; " << result << std::endl;
		}

		else
		{
			std::cout << "Database Empty" << std::endl;
		}

	    P(muteR);
		//mutexR.unlock();
		//mutexR.lock();
		//Pmutex(mutexR);

		numOfreaders--;
		//numOfreaders++;

		if (numOfreaders == 0)
		{
			V(muteW);
			//mutexW.lock();
			//mutexW.unlock();
			//Vmutex(mutexW);
		}
		V(muteR);
		//mutexR.lock();
		//mutexR.unlock();
		//Vmutex(mutexR);
	}
}

int main(int argc, char *argv[])
{
	std::thread w(Writer);
	//std::thread w2(Writer);
	std::thread c(Reader);
	//std::thread c2(Reader);

	w.join();
	c.join();
	//w2.join();
	//c2.join();

	while (true)
	{
		//Keep the progrmamme running
	}

	return 0;
}