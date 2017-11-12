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
#include "Menu.h"
#include "Audio.h"
#include "Ball.h"
#include "Contact.h"
#include "Emitter.h"

#include "HealthComponent.h"
#include "ControlSystem.h"
#include "RenderSystem.h"
#include "HealthSystem.h"
/** The game objct whic manages the game loop*/
class Game:public EventListener
{
	InputManager inputManager;
	unsigned int lastTime;//time of last update;

	bool pause = true;
	bool quit;
	bool nextLevel;
	bool drownState = false;

//	Renderer renderer;
	Contact contactListener;

	enum GameState {
		STARTSCREEN,
		GAMEPLAY,
		PAUSE,
		OPTIONS,
		ENDSCREEN,
	};

	SDL_Window* gameWindow;
	SDL_Renderer* gameRenderer;

	bool gameRunning = true;
	bool musicPlaying = false;


	bool wallBroke = false;
	SDL_Rect box;
	SDL_Point center;
	SDL_Texture* bWallTexture;

	Audio audio;

	SDL_Texture* startScreenTexture = NULL;
	//std::string path = "ASSETS/PhysicsStartScreen.png";
	Menu* startScreen;// = new Menu(path, gameRenderer, true);
	SDL_Texture* startScreenIcon = NULL;

	Ball ball;
	Emitter* iconParticles;
	Menu* endScreen;

	HealthSystem* healthSystem;
	Entity* player;
	HealthComponent* healthComponent;

public:
	Game();
	~Game();

	bool init();

	void TestLevel1();
	void TestLevel2();
	void TestLevel3();

	void destroy();

	void update();
	void render();
	void loop();

	void onEvent(EventListener::Event);

private:
	GameState gameState;
	b2Vec2 gravity;
	b2World* World;
	b2Body* playerBody;
	b2Vec2 playerPos;
	/*b2Body* groundBody;
	b2BodyDef groundBodyDef;*/
	/*b2Body* ballBody;
	b2BodyDef ballBodyDef;
	b2Vec2 ballVector;*/
	//b2PolygonShape groundBox;
	b2Body* body;
	b2Body* bbody;
	b2FixtureDef boxShapeDef;
	b2PolygonShape dynamicBox;
	b2FixtureDef fixtureDef;
	float timeStep;
	int velIter;
	int posIter;
	b2Vec2 pos;
	float angle;

	TTF_Font* Sans;
	SDL_Color White;
	SDL_Color Green;
	SDL_Color Red;
	SDL_Surface* surfaceMessage;
	SDL_Texture* optMessage;
	SDL_Texture* mVolMessage;
	SDL_Texture* seVolMessage;
	SDL_Texture* MuVolMessage;
	SDL_Texture* mVolNumMessage;
	SDL_Texture* seVolNumMessage;
	SDL_Texture* MuVolNumMessage;
	SDL_Texture* Message;
	SDL_Rect Message_rect; //create a rect
	SDL_Rect optMessage_rect;
	SDL_Rect mVolMessage_rect;
	SDL_Rect mVolNumMessage_rect;
	SDL_Rect seVolMessage_rect;
	SDL_Rect seVolNumMessage_rect;
	SDL_Rect muVolMessage_rect;
	SDL_Rect muVolNumMessage_rect;
	SDL_Rect tempPlayer;

	b2CircleShape playerShape;
	b2BodyDef playerDef;
	string pName;
	float playerAngle;
	short selectedOption;
	short mVol;
	short sEVol;
	short muVol;
	int musicVolume;
	int soundEffectsVolume;
	int masterVolume;
	bool renderInit = false;
	short selectedStartOption = 0;
};

