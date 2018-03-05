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

#include "HealthComponent.h"
#include "ControlComponent.h"
#include "RenderComponent.h"
#include "AIComponent.h"

#include"RenderSystem.h"
#include "AISystem.h"
#include "ControlSystem.h"

#include "HealthSystem.h"

struct item
{
	int id = 1;
};

/** The game objct whic manages the game loop*/
class Game:public EventListener
{
	InputManager inputManager;
	unsigned int lastTime;//time of last update;

	bool pause = true;
	bool quit;

	SDL_Window* gameWindow;
	SDL_Renderer* gameRenderer;

	bool gameRunning = true;
	bool musicPlaying = false;

	void Producer();
	void Consumer();

	std::vector<int> buffer;

	int front = 0, rear = 0;

	SDL_sem * empty = SDL_CreateSemaphore(buffer.capacity());
	SDL_sem * full = SDL_CreateSemaphore(0);

	item * protoItem;

public:
	Game();
	~Game();

	bool init();

	void destroy();

	void update();
	void render();
	void loop();

	void onEvent(EventListener::Event);

};

