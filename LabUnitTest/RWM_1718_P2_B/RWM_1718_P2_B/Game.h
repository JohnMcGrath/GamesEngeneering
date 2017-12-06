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

	HealthSystem* healthSystem;
	RenderSystem* renderSystem;
	AISystem* aiSystem;
	ControlSystem* controlSystem;

	Entity* player;
	Entity* alien;
	Entity* dog;
	Entity* cat;

	HealthComponent* healthComponent;
	RenderComponent* renderComponent;
	AIComponent* aiComponent;
	ControlComponent* controlComponent;

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

