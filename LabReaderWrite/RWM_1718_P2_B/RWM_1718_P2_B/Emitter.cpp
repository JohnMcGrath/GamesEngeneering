#include "Emitter.h"

Emitter::Emitter(int x, int y, SDL_Renderer *r)
{
	mXPos = x;
	mYPos = y;

	for (int i = 0; i < 20; ++i)
	{
		particles[i] = new Particle(mXPos, mYPos, r);
	}
}

void Emitter::Render(SDL_Renderer *r)
{
	for (int i = 0; i < 20; ++i)
	{
		if (particles[i]->isDead())
		{
			delete particles[i];
			particles[i] = new Particle(mXPos, mYPos, r);
		}
	}
	for (int i = 0; i < 16; ++i)
	{
		particles[i]->render(r);
	}
}