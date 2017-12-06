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


	aiSystem = new AISystem();
	controlSystem = new ControlSystem();
	renderSystem = new RenderSystem();

	healthComponent = new HealthComponent();
	controlComponent = new ControlComponent();
	renderComponent = new RenderComponent();

	player = new Entity();
	alien = new Entity();
	dog = new Entity();
	cat = new Entity();

	player->addComponent(healthComponent);
	player->addComponent(controlComponent);
	player->addComponent(renderComponent);
	aiSystem->addEntity(player);
	renderSystem->addEntity(player);
	controlSystem->addEntity(player);

	alien->addComponent(healthComponent);
	alien->addComponent(renderComponent);
	aiSystem->addEntity(alien);
	renderSystem->addEntity(alien);

	dog->addComponent(healthComponent);
	dog->addComponent(renderComponent);
	aiSystem->addEntity(dog);
	renderSystem->addEntity(dog);

	cat->addComponent(healthComponent);
	cat->addComponent(renderComponent);
	aiSystem->addEntity(cat);
	renderSystem->addEntity(cat);
}


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
	aiSystem->update();
	renderSystem->update();
	controlSystem->update();

	unsigned int currentTime = LTimer::gameTime();//millis since game started
	unsigned int deltaTime = currentTime - lastTime;//time since last update

													//save the curent time for next frame
	lastTime = currentTime;
}

//** calls render on all game entities*/

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