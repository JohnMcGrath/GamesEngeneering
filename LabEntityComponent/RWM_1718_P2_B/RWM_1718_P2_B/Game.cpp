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

const int BOX_START_X = 0, BOX_START_Y = 0;
const int BOX_WIDTH = 100, BOX_HEIGHT = 100;

/*
//const int GROUND_X = 0, GROUND_Y = 540;
//const int GROUND_WIDTH = SCREEN_WIDTH, GROUND_HEIGHT = SCREEN_HEIGHT - GROUND_Y;


// Width + Height of Board Rect
const int HOR_WIDTH = 600, HOR_HEIGHT = 50;
const int VER_WIDTH = 50, VER_HEIGHT = 600;
*/

/*

SDL_Surface* playerSurface;
SDL_Texture* playerTexture;

SDL_Surface* walls;
SDL_Texture* texture;

SDL_Rect nWall;
SDL_Point nWallCenter;
SDL_Rect sWall;
SDL_Point sWallCenter;
SDL_Rect wWall;
SDL_Point wWallCenter;
SDL_Rect eWall;
SDL_Point eWallCenter;
SDL_Rect bWall;
SDL_Point bWallCenter;
SDL_Rect bWall1;
SDL_Point bWallCenter1;
SDL_Rect bWall2;
SDL_Point bWallCenter2;
SDL_Rect bWall3;
SDL_Point bWallCenter3;


SDL_Point playerCenter;
SDL_Rect player;

*/

Game::Game()
{
	//Initialises SDL Image to use PNGs
	if (!(IMG_Init(IMG_INIT_PNG)))
	{
		std::cout << "Error : PNG Did not load";
	}

	musicPlaying = false;

	pause = false;
	quit = false;
	gameWindow = SDL_CreateWindow("My Puzzler", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	gameRenderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_PRESENTVSYNC);


	healthSystem = new HealthSystem();
	player = new Entity();
	healthComponent = new HealthComponent();

	player->addComponent(healthComponent);
	healthSystem->addEntity(player);







	/*
	std::string path = "ASSETS/PhysicsStartScreen.png";
	startScreen = new Menu(path, gameRenderer, true);

	path = "ASSETS/EndScreen.png";
	endScreen = new Menu(path, gameRenderer, true);

	path = "ASSETS/MenuCursor.png";
	startScreenIcon = IMG_LoadTexture(gameRenderer, path.c_str());

	//menus.push_back(startScreen);

	box.x = BOX_START_X, box.y = BOX_START_Y;
	box.w = BOX_WIDTH, box.h = BOX_HEIGHT;

	//ground.x = GROUND_X, ground.y = GROUND_Y;
	//ground.w = GROUND_WIDTH, ground.h = GROUND_HEIGHT;

	ball.ball = SDL_LoadBMP("ball.bmp");

	


	texture = SDL_CreateTextureFromSurface(gameRenderer, walls);
	inputManager.AddListener(EventListener::Event::OPTIONS, this);
	inputManager.AddListener(EventListener::Event::OPTIONUP, this);
	inputManager.AddListener(EventListener::Event::OPTIONDOWN, this);
	inputManager.AddListener(EventListener::Event::VOLUMEUP, this);
	inputManager.AddListener(EventListener::Event::VOLUMEDOWN, this);
	inputManager.AddListener(EventListener::Event::RESUMEGAME, this);
	inputManager.AddListener(EventListener::Event::STARTGAME, this);
	inputManager.AddListener(EventListener::Event::ENTER, this);
	inputManager.AddListener(EventListener::Event::ENDGAME, this);
	inputManager.AddListener(EventListener::Event::MOVELEFT, this);
	inputManager.AddListener(EventListener::Event::MOVERIGHT, this);
	inputManager.AddListener(EventListener::Event::RELEASE, this);
	*/
}


Game::~Game()
{
}


bool Game::init() {
/*
	iconParticles = new Emitter(310, 285, gameRenderer);
	audio.Init();
	if (!renderInit)
	{
		masterVolume = 100;
		soundEffectsVolume = 50;
		musicVolume = 50;
	}
	renderInit = false;
	Sans = TTF_OpenFont("arial.ttf", 100);

	White = { 255, 255, 255 };
	Green = { 0, 255, 0 };
	Red = { 255, 0, 0 };

	mVol = 0;
	sEVol = 1;
	muVol = 2;
	selectedOption = mVol;

	center.x = box.w * 0.5f;
	center.y = box.h * 0.5f;
	gameState = GameState::STARTSCREEN;

	*/

	/*groundBodyDef.type = b2_staticBody;
	groundBodyDef.position.Set(ground.x, ground.y);
	groundBody = World->CreateBody(&groundBodyDef);*/

	contactListener.Init();
	/*ball.Init();

	ball.ballBodyDef.type = b2_dynamicBody;
	ball.ballVector.Set(0, 0);
	ball.ballBodyDef.linearVelocity = ball.ballVector;
	ball.ballBodyDef.angularVelocity = 0.0f;
	ball.ballBodyDef.position.Set(0, 0);
	ball.ballBodyDef.awake = true;
	ball.ballBody = World->CreateBody(&ball.ballBodyDef);

	ball.ballBody->SetUserData(&ball.ballBody);*/
//	ball.ballBody->SetUserData(ball);

	/*boxShapeDef.shape = &groundBox;
	boxShapeDef.density = 2.0f;
	boxShapeDef.restitution = 0.5f;
	groundBox.SetAsBox(800, 0);

	groundBody->CreateFixture(&groundBox, 0);*/

/*
	dynamicBox.SetAsBox(BOX_WIDTH, BOX_HEIGHT);

	fixtureDef.shape = &dynamicBox;

	fixtureDef.density = 0.0f;
	fixtureDef.friction = 0.0f;
	fixtureDef.restitution = 0.5f;

	//ball.ballBody->CreateFixture(&fixtureDef);

	





	player.x = 555, player.y = 50, player.w = 50, player.h = 50;

	
	walls = SDL_LoadBMP("ASSETS/SolidWall.bmp");
	texture = SDL_CreateTextureFromSurface(gameRenderer, walls);

	playerTexture = IMG_LoadTexture(gameRenderer, "ASSETS/circle.png");
	bWallTexture = IMG_LoadTexture(gameRenderer, "ASSETS/BreakableWall.png");

	playerCenter.x = player.w * 0.5f, playerCenter.y = player.h * 0.5f;


	b2Vec2 gravity(0, 9.8f);

	gravity = b2Vec2(0, 9.8f);
	World = new b2World(gravity);
	World->SetGravity(gravity);

	World->SetContactListener(&contactListener);



	float width = 100.0f;
	float height = 5;
	//Commented values are expected values with width 1.5f and height 0.15f.

	b2PolygonShape bottom;
	//bottom.SetAsBox( 1.5f, 0.15f );
	//bottom.SetAsBox(width, height);
	bottom.SetAsBox(width, height, b2Vec2(0, -(width - height)), 0);

	b2PolygonShape left;
	//left.SetAsBox(1.5f, 0.15f, b2Vec2(-1.35f, 1.35f), b2_pi/2);
	//left.SetAsBox(width, height, b2Vec2(-(width-height), width-height), b2_pi/2);
	left.SetAsBox(width, height, b2Vec2(-(width - height), 0), b2_pi / 2);

	b2PolygonShape right;
	//right.SetAsBox(1.5f, 0.15f, b2Vec2(1.35f, 1.35f), b2_pi/2);
	//right.SetAsBox(width, height, b2Vec2(width - height, width - height), b2_pi/2);
	right.SetAsBox(width, height, b2Vec2(width - height, 0), b2_pi / 2);

	b2PolygonShape top;
	//top.SetAsBox(1.5f, 0.15f, b2Vec2(0, 2.7f), 0);
	//top.SetAsBox(width, height, b2Vec2(0, (width-height)*2), 0);
	top.SetAsBox(width, height, b2Vec2(0, width - height), 0);

	b2PolygonShape breakable;
	//top.SetAsBox(1.5f, 0.15f, b2Vec2(0, 2.7f), 0);
	//top.SetAsBox(width, height, b2Vec2(0, (width-height)*2), 0);
	breakable.SetAsBox(width/3.0f + 15, 20, b2Vec2(-60, -50), 0);

	b2PolygonShape broken1;
	//top.SetAsBox(1.5f, 0.15f, b2Vec2(0, 2.7f), 0);
	//top.SetAsBox(width, height, b2Vec2(0, (width-height)*2), 0);
	broken1.SetAsBox(width / 3.0f + 15, 20, b2Vec2(-20, -50), 0);

	b2PolygonShape broken2;
	//top.SetAsBox(1.5f, 0.15f, b2Vec2(0, 2.7f), 0);
	//top.SetAsBox(width, height, b2Vec2(0, (width-height)*2), 0);
	broken2.SetAsBox(width / 3.0f + 35, 20, b2Vec2(-20, -50), 0);

	b2PolygonShape broken3;
	//top.SetAsBox(1.5f, 0.15f, b2Vec2(0, 2.7f), 0);
	//top.SetAsBox(width, height, b2Vec2(0, (width-height)*2), 0);
	broken3.SetAsBox(width / 3.0f + 55, 20, b2Vec2(-20, -50), 0);


	b2BodyDef bd;
	bd.type = b2_kinematicBody;
	bd.position.Set(0.0f, 0.0f);
	bd.angularVelocity = 0.0f;
	bd.gravityScale = 0.0f;
	body = World->CreateBody(&bd);
	body->CreateFixture(&bottom, 4.0f);
	body->CreateFixture(&left, 4.0f);
	body->CreateFixture(&right, 4.0f);
	body->CreateFixture(&top, 4.0f);
	body->CreateFixture(&breakable, 4.0f);

	//b2BodyDef dbd;
	//dbd.type = b2_dynamicBody;
	//dbd.position.Set(0.0f, 0.0f);
	//dbd.angularVelocity = 0.0f;
	//dbd.gravityScale = 0.0f;
	//bbody = World->CreateBody(&dbd);
	//bbody->CreateFixture(&broken1, 1.0f);
	//bbody->CreateFixture(&broken2, 1.0f);
	//bbody->CreateFixture(&broken3, 1.0f);


	playerShape.m_radius = 2.0f;
	playerShape.m_p.Set(0.0f, 0.0f);
	playerDef.type = b2_dynamicBody;
	playerDef.position.Set(0, 0);

	playerBody = World->CreateBody(&playerDef);
	playerBody->CreateFixture(&playerShape, 2.0f);

	const int NWALL_START_X = (SCREEN_WIDTH / 2) - (HOR_WIDTH / 2), NWALL_START_Y = (SCREEN_HEIGHT / 2) - (VER_HEIGHT / 2);
	const int SWALL_START_X = (SCREEN_WIDTH / 2) - (HOR_WIDTH / 2), SWALL_START_Y = (SCREEN_HEIGHT / 2) + (VER_HEIGHT / 2) - (HOR_HEIGHT);
	const int EWALL_START_X = (SCREEN_WIDTH / 2) + (HOR_WIDTH / 2) - (VER_WIDTH), EWALL_START_Y = (SCREEN_HEIGHT / 2) - (VER_HEIGHT / 2);
	const int WWALL_START_X = (SCREEN_WIDTH / 2) - (HOR_WIDTH / 2), WWALL_START_Y = (SCREEN_HEIGHT / 2) - (VER_HEIGHT / 2);

	// Starting positions of the grid rect to draw
	nWall.x = NWALL_START_X, nWall.y = NWALL_START_Y, nWall.w = HOR_WIDTH, nWall.h = HOR_HEIGHT;
	sWall.x = SWALL_START_X, sWall.y = SWALL_START_Y, sWall.w = HOR_WIDTH, sWall.h = HOR_HEIGHT;
	eWall.x = EWALL_START_X, eWall.y = EWALL_START_Y, eWall.w = VER_WIDTH, eWall.h = VER_HEIGHT;
	wWall.x = WWALL_START_X, wWall.y = WWALL_START_Y, wWall.w = VER_WIDTH, wWall.h = VER_HEIGHT;
	bWall.x = NWALL_START_X + VER_WIDTH, bWall.y = VER_WIDTH * 3, bWall.h = VER_WIDTH, bWall.w = 200;
	//bWall1.x = NWALL_START_X + VER_WIDTH, bWall1.y = VER_WIDTH * 3, bWall1.h = VER_WIDTH, bWall1.w = 70;
	//bWall2.x = NWALL_START_X + VER_WIDTH + 70, bWall2.y = VER_WIDTH * 3, bWall2.h = VER_WIDTH, bWall2.w = 60;
	//bWall3.x = NWALL_START_X + VER_WIDTH + 130, bWall3.y = VER_WIDTH * 3, bWall3.h = VER_WIDTH, bWall3.w = 70;


	// centres around which walls are rotated
	nWallCenter.x = HOR_WIDTH / 2, nWallCenter.y = VER_HEIGHT / 2;
	sWallCenter.x = HOR_WIDTH / 2, sWallCenter.y = -(VER_HEIGHT / 2) + HOR_HEIGHT;
	eWallCenter.x = -(HOR_WIDTH / 2) + VER_WIDTH, eWallCenter.y = VER_HEIGHT / 2;
	wWallCenter.x = HOR_WIDTH / 2, wWallCenter.y = VER_HEIGHT / 2;
	bWallCenter.x = HOR_WIDTH / 2 - 1 *VER_WIDTH, bWallCenter.y = VER_HEIGHT / 2 - 3 *VER_WIDTH;
	//bWallCenter1.x = HOR_WIDTH / 2 -50, bWallCenter1.y = VER_HEIGHT / 2 - 3 * VER_WIDTH;
	//bWallCenter2.x = HOR_WIDTH / 2 - 120, bWallCenter2.y = VER_HEIGHT / 2 - 3 * VER_WIDTH;
	//bWallCenter3.x = HOR_WIDTH / 2 - 180, bWallCenter3.y = VER_HEIGHT / 2 - 3 * VER_WIDTH;

	timeStep = 0.1f;
	velIter = 10;
	posIter = 100;

	*/

	return true;
}

void Game::destroy()
{
/*	SDL_DestroyTexture(texture);
	SDL_DestroyTexture(bWallTexture);
	SDL_DestroyTexture(playerTexture);
	SDL_FreeSurface(walls);
	SDL_FreeSurface(playerSurface);*/

	SDL_DestroyWindow(gameWindow);
	SDL_DestroyRenderer(gameRenderer);

	SDL_Quit();
}

//** calls update on all game entities*/
void Game::update()
{
	/*
	if (gameState == GameState::GAMEPLAY)
	{
		World->Step(timeStep, velIter, posIter);
		pos = ball.ballBody->GetPosition();
		angle = ball.ballBody->GetAngle();
		box.x = pos.x;
		box.y = pos.y;

		angle = body->GetAngle();

		angle = 180 / 3.14 * angle;

		playerPos = playerBody->GetPosition();
		playerAngle = playerBody->GetAngle();

		playerAngle = 180 / 3.14 * playerAngle;

		player.x = playerPos.x;
		player.y = playerPos.y;

		tempPlayer = player;

		tempPlayer.x = (SCREEN_WIDTH / 2) + ((player.x*2.5) - ((player.w / 2.5)));
		tempPlayer.y = (SCREEN_HEIGHT / 2) + ((player.y*2.5) - ((player.h / 2.5)));
		//tempPlayer.y = (SCREEN_HEIGHT/2) + (player.y - player.h / 2);



	}

	if (gameState == GameState::OPTIONS)
	{

	}
	*/
	unsigned int currentTime = LTimer::gameTime();//millis since game started
	unsigned int deltaTime = currentTime - lastTime;//time since last update

													//save the curent time for next frame
	lastTime = currentTime;
}

//** calls render on all game entities*/

void Game::render()
{
	//cout << ball.m_numContacts << endl;
	//Menu* startScreen = new Menu(path, gameRenderer, true);
/*	if (gameState == GameState::ENDSCREEN)
	{
		SDL_RenderClear(gameRenderer);
		SDL_RenderCopy(gameRenderer, endScreen->getTexture(), nullptr, nullptr);
		SDL_RenderPresent(gameRenderer);
	}

	if (gameState == GameState::OPTIONS)
	{
		SDL_RenderClear(gameRenderer);
		SDL_SetRenderDrawColor(gameRenderer, 25, 51, 235, 0);
	}

	else if (gameState == GameState::GAMEPLAY)
	{
		SDL_RenderClear(gameRenderer);

		SDL_SetRenderDrawColor(gameRenderer, 135, 206, 235, 0);

		SDL_RendererFlip Flip = SDL_FLIP_NONE;

		SDL_RenderCopyEx(gameRenderer, texture, NULL, &nWall, angle, &nWallCenter, Flip);
		SDL_RenderCopyEx(gameRenderer, texture, NULL, &sWall, angle, &sWallCenter, Flip);
		SDL_RenderCopyEx(gameRenderer, texture, NULL, &wWall, angle, &wWallCenter, Flip);
		SDL_RenderCopyEx(gameRenderer, texture, NULL, &eWall, angle, &eWallCenter, Flip);

		SDL_RenderCopyEx(gameRenderer, bWallTexture, NULL, &bWall, angle, &bWallCenter, Flip);
		//SDL_RenderCopyEx(gameRenderer, bWallTexture, NULL, &bWall1, angle, &bWallCenter1, Flip);
		//SDL_RenderCopyEx(gameRenderer, bWallTexture, NULL, &bWall2, angle, &bWallCenter2, Flip);
		//SDL_RenderCopyEx(gameRenderer, bWallTexture, NULL, &bWall3, angle, &bWallCenter3, Flip);

		SDL_RenderCopyEx(gameRenderer, playerTexture, NULL, &tempPlayer, playerAngle, &playerCenter, Flip);

	}

	else if (gameState == GameState::STARTSCREEN)
	{

		// clear the screen
		SDL_RenderClear(gameRenderer);

		Message_rect.x = 310;  //controls the rect's x coordinate 
		iconParticles->setXPos(310);

		Message_rect.w = 25; // controls the width of the rect
		Message_rect.h = 25; // controls the height of the rect

		if (selectedStartOption == 0)
		{
			Message_rect.y = 285; // controls the rect's y coordinte
			iconParticles->setYPos(285);
		}

		else if (selectedStartOption == 1)
		{
			Message_rect.y = 355; // controls the rect's y coordinte
			iconParticles->setYPos(355);
		}

		else
		{
			Message_rect.y = 415; // controls the rect's y coordinte
			iconParticles->setYPos(415);
		}
		//Copy to the renderer
		SDL_RenderCopy(gameRenderer, startScreen->getTexture(), nullptr, nullptr);
		iconParticles->Render(gameRenderer);
		SDL_RenderCopy(gameRenderer, startScreenIcon, nullptr, &Message_rect);
		//Present 
		SDL_RenderPresent(gameRenderer);

	}

	//SDL_RenderClear(gameRenderer);

	if (gameState == GameState::GAMEPLAY)
	{
		SDL_RendererFlip Flip = SDL_FLIP_NONE;

		//SDL_RenderCopyEx(gameRenderer, texture, NULL, &box, angle, &center, Flip);

		if (contactListener.m_numContacts == 0)
		{
			SDL_SetRenderDrawColor(gameRenderer, 96, 128, 56, 0);
			//SDL_RenderFillRect(gameRenderer, &ground);
		}
		else
		{
			SDL_SetRenderDrawColor(gameRenderer, 255, 128, 56, 0);
			//SDL_RenderFillRect(gameRenderer, &ground);
		}
	}
	else if (gameState == GameState::OPTIONS)
	{

		surfaceMessage = TTF_RenderText_Solid(Sans, "Options", White);
		if (!renderInit)
		{
			optMessage = SDL_CreateTextureFromSurface(gameRenderer, surfaceMessage);
			optMessage_rect.x = 280;  //controls the rect's x coordinate 
			optMessage_rect.y = 10; // controls the rect's y coordinte
			optMessage_rect.w = 250; // controls the width of the rect
			optMessage_rect.h = 88; // controls the height of the rect
		}

		SDL_RenderCopy(gameRenderer, optMessage, NULL, &optMessage_rect);

		if (!renderInit)
		{
			surfaceMessage = TTF_RenderText_Solid(Sans, "Master", Green);
			mVolMessage = SDL_CreateTextureFromSurface(gameRenderer, surfaceMessage);
			mVolMessage_rect.x = 50;  //controls the rect's x coordinate 
			mVolMessage_rect.y = 125; // controls the rect's y coordinte
			mVolMessage_rect.w = 200; // controls the width of the rect
			mVolMessage_rect.h = 75; // controls the height of the rect
		}

		SDL_RenderCopy(gameRenderer, mVolMessage, NULL, &mVolMessage_rect);

		if (!renderInit)
		{
			string s = to_string(masterVolume);	//creates a string using the master volume int
			const char* c = s.c_str();	//converts the master volume into a char
			surfaceMessage = TTF_RenderText_Solid(Sans, c, White);	//creates an SDL surface for the text
			mVolNumMessage = SDL_CreateTextureFromSurface(gameRenderer, surfaceMessage);
			mVolNumMessage_rect.y = 125; // controls the rect's y coordinte
			mVolNumMessage_rect.h = 75; // controls the height of the rect
		}
		if (masterVolume < 10)
		{
			mVolNumMessage_rect.x = 469;  //controls the rect's x coordinate 
			mVolNumMessage_rect.w = 38; // controls the width of the rect
		}
		else if (masterVolume == 100)
		{
			mVolNumMessage_rect.x = 431;  //controls the rect's x coordinate 
			mVolNumMessage_rect.w = 113; // controls the width of the rect
		}
		else
		{
			mVolNumMessage_rect.x = 450;  //controls the rect's x coordinate 
			mVolNumMessage_rect.w = 75; // controls the width of the rect
		}
		SDL_RenderCopy(gameRenderer, mVolNumMessage, NULL, &mVolNumMessage_rect);
		if (!renderInit)
		{
			surfaceMessage = TTF_RenderText_Solid(Sans, "Sound Effects", Red);
			seVolMessage = SDL_CreateTextureFromSurface(gameRenderer, surfaceMessage);
			seVolMessage_rect.x = 50;  //controls the rect's x coordinate 
			seVolMessage_rect.y = 325; // controls the rect's y coordinte
			seVolMessage_rect.w = 300; // controls the width of the rect
			seVolMessage_rect.h = 75; // controls the height of the rect
		}

		SDL_RenderCopy(gameRenderer, seVolMessage, NULL, &seVolMessage_rect);
		if (!renderInit)
		{
			string ssev = to_string(soundEffectsVolume);	//creates a string using the sound effects volume int
			const char* csev = ssev.c_str();	//converts the sound effects volume into a char
			surfaceMessage = TTF_RenderText_Solid(Sans, csev, White);	//creates an SDL surface for the text
			seVolNumMessage = SDL_CreateTextureFromSurface(gameRenderer, surfaceMessage);
			seVolNumMessage_rect.y = 325; // controls the rect's y coordinte
			seVolNumMessage_rect.h = 75; // controls the height of the rect
		}
		if (soundEffectsVolume < 10)
		{
			seVolNumMessage_rect.x = 469;  //controls the rect's x coordinate 
			seVolNumMessage_rect.w = 38; // controls the width of the rect
		}
		else if (soundEffectsVolume == 100)
		{
			seVolNumMessage_rect.x = 431;  //controls the rect's x coordinate 
			seVolNumMessage_rect.w = 113; // controls the width of the rect
		}
		else
		{
			seVolNumMessage_rect.x = 450;  //controls the rect's x coordinate 
			seVolNumMessage_rect.w = 75; // controls the width of the rect
		}
		SDL_RenderCopy(gameRenderer, seVolNumMessage, NULL, &seVolNumMessage_rect);
		if (!renderInit)
		{
			surfaceMessage = TTF_RenderText_Solid(Sans, "Music", Red);
			MuVolMessage = SDL_CreateTextureFromSurface(gameRenderer, surfaceMessage);
			muVolMessage_rect.x = 50;  //controls the rect's x coordinate 
			muVolMessage_rect.y = 525; // controls the rect's y coordinte
			muVolMessage_rect.w = 200; // controls the width of the rect
			muVolMessage_rect.h = 75; // controls the height of the rect
		}


		SDL_RenderCopy(gameRenderer, MuVolMessage, NULL, &muVolMessage_rect);
		if (!renderInit)
		{

			string smv = to_string(musicVolume);	//creates a string using the music volume int
			const char* cmv = smv.c_str();	//converts the music volume into a char
			surfaceMessage = TTF_RenderText_Solid(Sans, cmv, White);	//creates an SDL surface for the text

			MuVolNumMessage = SDL_CreateTextureFromSurface(gameRenderer, surfaceMessage);
			muVolNumMessage_rect.y = 525; // controls the rect's y coordinte
			muVolNumMessage_rect.h = 75; // controls the height of the rect
		}
		if (musicVolume < 10)
		{
			muVolNumMessage_rect.x = 469;  //controls the rect's x coordinate 
			muVolNumMessage_rect.w = 38; // controls the width of the rect
		}
		else if (musicVolume == 100)
		{
			muVolNumMessage_rect.x = 431;  //controls the rect's x coordinate 
			muVolNumMessage_rect.w = 113; // controls the width of the rect
		}
		else
		{
			muVolNumMessage_rect.x = 450;  //controls the rect's x coordinate 
			muVolNumMessage_rect.w = 75; // controls the width of the rect
		}
		SDL_RenderCopy(gameRenderer, MuVolNumMessage, NULL, &muVolNumMessage_rect);
		renderInit = true;
	}
	*/
	SDL_RenderPresent(gameRenderer);
}

/** update and render game entities*/
void Game::loop()
{
	LTimer capTimer;//to cap framerate
	
	int frameNum = 0;
	while (!quit) { //game loop
		/*if (GameState::GAMEPLAY)
		{
			if (musicPlaying == false)
			{
				musicPlaying = true;
				audio.Play();
			}
			audio.Update(masterVolume, musicVolume, soundEffectsVolume);
		}
		*/
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

void Game::onEvent(EventListener::Event evt) {

	/*if (evt == EventListener::Event::OPTIONS) {
		gameState = GameState::OPTIONS;
	}
	if (evt == EventListener::Event::RESUMEGAME) {
		gameState = GameState::GAMEPLAY;
	}
	if (evt == EventListener::Event::STARTGAME) {
		init();
	}

	if (evt == EventListener::Event::ENDGAME)
	{
		gameState = GameState::ENDSCREEN;
	}
	if (evt == EventListener::Event::ENTER)
	{
		if (gameState == GameState::STARTSCREEN)
		{
			if (selectedStartOption == 0)
			{
				gameState = GameState::GAMEPLAY;
			}
			else if (selectedStartOption == 1)
			{
				gameState = GameState::OPTIONS;
			}
			else
			{
				quit = true;
			}
		}
	}

	if (evt == EventListener::Event::OPTIONUP) {
		if (gameState == GameState::OPTIONS)
		{
			if (selectedOption == muVol)
			{
				//changes the selected option making the text for the newly selected option green 
				//and the previously selected option back to the defaul red text
				selectedOption = sEVol;
				surfaceMessage = TTF_RenderText_Solid(Sans, "Sound Effects", Green);
				seVolMessage = SDL_CreateTextureFromSurface(gameRenderer, surfaceMessage);
				surfaceMessage = TTF_RenderText_Solid(Sans, "Music", Red);
				MuVolMessage = SDL_CreateTextureFromSurface(gameRenderer, surfaceMessage);
			}
			else if (selectedOption == sEVol)
			{
				//changes the selected option making the text for the newly selected option green 
				//and the previously selected option back to the defaul red text
				selectedOption = mVol;
				surfaceMessage = TTF_RenderText_Solid(Sans, "Master", Green);
				mVolMessage = SDL_CreateTextureFromSurface(gameRenderer, surfaceMessage);
				surfaceMessage = TTF_RenderText_Solid(Sans, "Sound Effects", Red);
				seVolMessage = SDL_CreateTextureFromSurface(gameRenderer, surfaceMessage);
			}
			else
			{
				//changes the selected option making the text for the newly selected option green 
				//and the previously selected option back to the defaul red text
				selectedOption = muVol;
				surfaceMessage = TTF_RenderText_Solid(Sans, "Music", Green);
				MuVolMessage = SDL_CreateTextureFromSurface(gameRenderer, surfaceMessage);
				surfaceMessage = TTF_RenderText_Solid(Sans, "Master", Red);
				mVolMessage = SDL_CreateTextureFromSurface(gameRenderer, surfaceMessage);
			}
		}
		if (gameState == GameState::STARTSCREEN)
		{
			if (selectedStartOption > 0)
			{
				selectedStartOption--;
				std::cout << selectedStartOption << std::endl;
			}
			else
			{
				selectedStartOption = 2;
				std::cout << selectedStartOption << std::endl;
			}
		}

	}
	if (evt == EventListener::Event::OPTIONDOWN) {
		if (gameState == GameState::OPTIONS)
		{
			if (selectedOption == mVol)
			{
				//changes the selected option making the text for the newly selected option green 
				//and the previously selected option back to the defaul red text
				selectedOption = sEVol;
				surfaceMessage = TTF_RenderText_Solid(Sans, "Sound Effects", Green);
				seVolMessage = SDL_CreateTextureFromSurface(gameRenderer, surfaceMessage);
				surfaceMessage = TTF_RenderText_Solid(Sans, "Master", Red);
				mVolMessage = SDL_CreateTextureFromSurface(gameRenderer, surfaceMessage);
			}
			else if (selectedOption == sEVol)
			{
				//changes the selected option making the text for the newly selected option green 
				//and the previously selected option back to the defaul red text
				selectedOption = muVol;
				surfaceMessage = TTF_RenderText_Solid(Sans, "Music", Green);
				MuVolMessage = SDL_CreateTextureFromSurface(gameRenderer, surfaceMessage);
				surfaceMessage = TTF_RenderText_Solid(Sans, "Sound Effects", Red);
				seVolMessage = SDL_CreateTextureFromSurface(gameRenderer, surfaceMessage);
			}
			else
			{
				//changes the selected option making the text for the newly selected option green 
				//and the previously selected option back to the defaul red text
				selectedOption = mVol;
				surfaceMessage = TTF_RenderText_Solid(Sans, "Master", Green);
				mVolMessage = SDL_CreateTextureFromSurface(gameRenderer, surfaceMessage);
				surfaceMessage = TTF_RenderText_Solid(Sans, "Music", Red);
				MuVolMessage = SDL_CreateTextureFromSurface(gameRenderer, surfaceMessage);

			}
		}
		if (gameState == GameState::STARTSCREEN)
		{
			if (selectedStartOption < 2)
			{
				selectedStartOption++;
				std::cout << selectedStartOption << std::endl;
			}
			else
			{
				selectedStartOption = 0;
				std::cout << selectedStartOption << std::endl;
			}
		}
	}
	if (evt == EventListener::Event::VOLUMEUP) {
		if (gameState == GameState::OPTIONS)
		{
			if (selectedOption == mVol)
			{
				if (masterVolume < 100)
				{
					masterVolume++;
				}
				else
				{
					masterVolume = 100;
				}
				//updates the message texture to signify the change in volume value
				string s = to_string(masterVolume);	//creates a string using the master volume int
				const char* c = s.c_str();	//converts the master volume into a char
				surfaceMessage = TTF_RenderText_Solid(Sans, c, White);	//creates an SDL surface for the text
				mVolNumMessage = SDL_CreateTextureFromSurface(gameRenderer, surfaceMessage);
			}
			else if (selectedOption == sEVol)
			{
				if (soundEffectsVolume < 100)
				{
					soundEffectsVolume++;
				}
				else
				{
					soundEffectsVolume = 100;
				}
				//updates the message texture to signify the change in volume value
				string ssev = to_string(soundEffectsVolume);	//creates a string using the sound effects volume int
				const char* csev = ssev.c_str();	//converts the sound effects volume into a char
				surfaceMessage = TTF_RenderText_Solid(Sans, csev, White);	//creates an SDL surface for the text
				seVolNumMessage = SDL_CreateTextureFromSurface(gameRenderer, surfaceMessage);
			}
			else if (selectedOption == muVol)
			{
				if (musicVolume < 100)
				{
					musicVolume++;
				}
				else
				{
					musicVolume = 100;
				}
				//updates the message texture to signify the change in volume value
				string smv = to_string(musicVolume);	//creates a string using the music volume int
				const char* cmv = smv.c_str();	//converts the music volume into a char
				surfaceMessage = TTF_RenderText_Solid(Sans, cmv, White);	//creates an SDL surface for the text

				MuVolNumMessage = SDL_CreateTextureFromSurface(gameRenderer, surfaceMessage);
			}
		}
	}
	if (evt == EventListener::Event::VOLUMEDOWN) {
		if (gameState == GameState::OPTIONS)
		{
			if (selectedOption == mVol)
			{
				if (masterVolume > 0)
				{
					masterVolume--;
				}
				else
				{
					masterVolume = 0;
				}
				//updates the message texture to signify the change in volume value
				string s = to_string(masterVolume);	//creates a string using the master volume int
				const char* c = s.c_str();	//converts the master volume into a char
				surfaceMessage = TTF_RenderText_Solid(Sans, c, White);	//creates an SDL surface for the text

				mVolNumMessage = SDL_CreateTextureFromSurface(gameRenderer, surfaceMessage);
			}
			else if (selectedOption == sEVol)
			{
				if (soundEffectsVolume > 0)
				{
					soundEffectsVolume--;
				}
				else
				{
					soundEffectsVolume = 0;
				}
				//updates the message texture to signify the change in volume value
				string ssev = to_string(soundEffectsVolume);	//creates a string using the sound effects volume int
				const char* csev = ssev.c_str();	//converts the sound effects volume into a char
				surfaceMessage = TTF_RenderText_Solid(Sans, csev, White);	//creates an SDL surface for the text
				seVolNumMessage = SDL_CreateTextureFromSurface(gameRenderer, surfaceMessage);
			}
			else if (selectedOption == muVol)
			{
				if (musicVolume > 0)
				{
					musicVolume--;
				}
				else
				{
					musicVolume = 0;
				}
				//updates the message texture to signify the change in volume value
				string smv = to_string(musicVolume);	//creates a string using the music volume int
				const char* cmv = smv.c_str();	//converts the music volume into a char
				surfaceMessage = TTF_RenderText_Solid(Sans, cmv, White);	//creates an SDL surface for the text

				MuVolNumMessage = SDL_CreateTextureFromSurface(gameRenderer, surfaceMessage);
			}
		}
	}
	if (evt == EventListener::Event::BREAKGLASS) {
		wallBroke = true;
	}
	if (evt == EventListener::Event::MOVELEFT) {
		if (gameState == GameState::GAMEPLAY)
		{
			body->SetAngularVelocity(-0.5);
		}
	}
	if (evt == EventListener::Event::MOVERIGHT) {
		if (gameState == GameState::GAMEPLAY)
		{
			body->SetAngularVelocity(0.5);
		}
	}
	if (evt == EventListener::Event::RELEASE) {
		if (gameState == GameState::GAMEPLAY)
		{
			body->SetAngularVelocity(0);
		}
	}
	*/
}