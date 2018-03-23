#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct item
{
	//Random number in each one
	
	int id = rand() % 100;
};

class Semaphore
{
public:

	void V()
	{
		//This lock must be aquired in order to wait on the condition variable
		std::unique_lock<decltype(m_mutex)> lock(m_mutex);
		++m_count;
		m_conditionVariable.notify_one();
	}

	void P()
	{
		//This lock must be aquired in order to wait on the condition variable
		std::unique_lock<decltype(m_mutex)> lock(m_mutex);
		while (m_count <= 0)
		{
			m_conditionVariable.wait(lock);
		}
		--m_count;
	}

private:
	int m_count = 1;

	//Used to block multiple threads until notified
	condition_variable m_conditionVariable;

	std::mutex m_mutex;
};

std::vector<item> database;

int numOfreaders = 0;

int muteW = 1;
int muteR = 1;

//Reader
Semaphore r;

//Writer
Semaphore w;

//Item used to create new ones
item protoItem;

int result;

void Writer();
void Reader();

void Writer()
{
	while (true)
	{
		//Create Item
		protoItem = item();

		//Grab the lock
		w.P();

		//Create an item and push to the database
		database.push_back(protoItem);
		std::cout << "Wrote Item to Database; Size: " << database.size() << std::endl;

		//Release the lock
		w.V();

		//Wait for half a second
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}

void Reader()
{
	while (true)
	{
		//Grabs reader lock
		r.P();
		
		//Increase the number of readers
		numOfreaders++;

		//Lock out writers if there's a reader
		if (numOfreaders == 1)
		{
			//Grab the writer lock
			w.P();
		}

		//Releases Reader Lock
		r.V();

		//Read a random database member
		if (database.size() != 0)
		{
			std::cout << "Reading Random Database Entry" << std::endl;
		}

		else
		{
			std::cout << "Database Empty" << std::endl;
		}

		//Grab the reader lock
		//Locking while we check the current amount of readers
		r.P();

		numOfreaders--;

		//If there are no readers
		if (numOfreaders == 0)
		{
			//Release the writer lock
			w.V();
		}

		//Grab lock
		r.V();

		//Wait for half a second
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
}

int main(int argc, char *argv[])
{
	std::thread w(Writer);
	std::thread w2(Writer);
	std::thread w3(Writer);

	std::thread c2(Reader);
	std::thread c(Reader);
	std::thread c3(Reader);

	w.join();
	w2.join();
	w3.join();

	c.join();
	c2.join();
	c3.join();

	while (true)
	{
		//Keep the progrmamme running
	}

	return 0;
}