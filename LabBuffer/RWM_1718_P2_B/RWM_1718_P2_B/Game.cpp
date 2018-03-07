#include <iostream>
using namespace std;

#include "LTimer.h"
#include "Game.h"
#include <stdlib.h>
#include <stdio.h>
#include "InputManager.h"
#include <iostream>
#include "Box2D\Box2D.h"
#include "Menu.h"


const int SCREEN_FPS = 100;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

Game::Game()
{
	pause = false;
	quit = false;
	gameWindow = SDL_CreateWindow("My Puzzler", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	gameRenderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_PRESENTVSYNC);
}

//void Producer()
//{
//	while (true)
//	{
//		protoItem = item();
//		
//		P(empty);
//
//		P(muteP);
//
//		buffer.push_back(protoItem);
//
//		V(muteP);
//
//		V(full);
//	}
//}
//
//void Consumer()
//{
//	while (true)
//	{
//		protoItem = item();
//		protoItem.id = 2;
//
//		P(full);
//
//		P(muteC);
//
//		buffer.push_back(protoItem);
//
//		V(muteC);
//
//		V(empty);
//
//		std::cout << std::endl;
//	}
//}

Game::~Game()
{
}


bool Game::init()
{
	return true;
}

void Game::destroy()
{
	SDL_DestroyWindow(gameWindow);
	SDL_DestroyRenderer(gameRenderer);

	SDL_Quit();
}

//** calls update on all game entities*/
void Game::update()
{
	unsigned int currentTime = LTimer::gameTime();//millis since game started
	unsigned int deltaTime = currentTime - lastTime;//time since last update

													//save the curent time for next frame
	lastTime = currentTime;

	//std::thread p1(this->Producer);
	//std::thread c1(this->Consumer);

}

void Game::render()
{
	SDL_RenderPresent(gameRenderer);
}

/** update and render game entities*/
void Game::loop()
{
	LTimer capTimer;//to cap framerate
	
	int frameNum = 0;
	while (!quit) { //game loop

		capTimer.start();

		inputManager.ProcessInput(false);
		if (!pause) //in pause mode don't bother updateing
			update();
		render();

		int frameTicks = capTimer.getTicks();//time since start of frame
		if (frameTicks < SCREEN_TICKS_PER_FRAME)
		{
			//Wait remaining time before going to next frame
			SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
		}
	}
}

void Game::onEvent(EventListener::Event evt)
{

}