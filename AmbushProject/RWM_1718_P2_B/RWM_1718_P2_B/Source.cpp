#include "Source.h"

using namespace std;

MapLoader m_mapLoader;
Renderer m_render;
Enemy* m_enemy;

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

int numOfreaders = 0;

int muteW = 1;
int muteR = 1;

//Reader
Semaphore r;

//Writer
Semaphore w;

int result;

void Writer();
void Reader();

void Init()
{
	m_enemy = new Enemy(m_render.getRenderer());
}

void Gameplay()
{
	m_render.DrawTiles(m_mapLoader.getFloorTiles(),m_mapLoader.getWallTiles());
	m_enemy->Render();
}

void Writer()
{
	while (true)
	{
		//Grab the lock
		w.P();

		/*
		Do whatever writing is needed
		*/
		std::cout << "\n" <<"Rewrite heurisitc value" << std::endl;

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

		/*
			Do whatever reading I need here
		*/
		std::cout << "\n" << "Pathfinding" << std::endl;

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
	
	std::thread g(Gameplay);
	
	std::thread c(Reader);


	w.join();

	g.join();

	c.join();

	

	while (true)
	{
		//Keep the progrmamme running
	}

	return 0;
}