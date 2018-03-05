#include "Particle.h"

Particle::Particle(int x, int y, SDL_Renderer *r)
{
	mXPos = x - 5 + (rand() % 25);
	mYPos = y - 5 + (rand() % 25);

	mFrame = rand() % 5;

	std::string tempPath;

	switch (rand() % 12)
	{
	case 0:
		tempPath = "ASSETS/bluesquare.png";
		break;
	case 1:
		tempPath = "ASSETS/bluediamond.png";
		break;
	case 2:
		tempPath = "ASSETS/bluetriangle.png";
		break;
	case 3:
		tempPath = "ASSETS/icebluesquare.png";
		break;
	case 4:
		tempPath = "ASSETS/icebluediamond.png";
		break;
	case 5:
		tempPath = "ASSETS/icebluetriangle.png";
		break;
	case 6:
		tempPath = "ASSETS/lightbluesquare.png";
		break;
	case 7:
		tempPath = "ASSETS/lightbluediamond.png";
		break;
	case 8:
		tempPath = "ASSETS/lightbluetriangle.png";
		break;
	case 9:
		tempPath = "ASSETS/skybluesquare.png";
		break;
	case 10:
		tempPath = "ASSETS/skybluediamond.png";
		break;
	case 11:
		tempPath = "ASSETS/skybluetriangle.png";
		break;
	}

	mTexture = IMG_LoadTexture(r, tempPath.c_str());
}

void Particle::render(SDL_Renderer *r)
{
	rect.x = mXPos;
	rect.y = mYPos;
	rect.w = 10;
	rect.h = 10;

	if (!isDead()) 
	{
		SDL_RenderCopy(r, mTexture, nullptr, &rect);
	}


	mFrame++;
}

bool Particle::isDead()
{
	return mFrame > 5;
}