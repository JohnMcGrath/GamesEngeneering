#pragma once
#include <vector>
#include "InputManager.h"
#include "EventListener.h"
#include "LTimer.h"
#include <string>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include "InputManager.h"
#include <iostream>
#include "Box2D\Box2D.h"
#include "SDL.h"
#include "SDL_ttf.h"
#include "Renderer.h"

class Particle
{
public:
	Particle(int x, int y, SDL_Renderer *r);

	void render(SDL_Renderer *r);

	bool isDead();

	SDL_Texture* getTexture() { 
		std::cout << "getting the texture";
		return mTexture; };

private:
	int mXPos;
	int mYPos;
	int mFrame;
	
	SDL_Texture *mTexture;
	SDL_Rect rect;
};