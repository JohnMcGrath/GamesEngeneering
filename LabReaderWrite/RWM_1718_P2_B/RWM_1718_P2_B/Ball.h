#pragma once


#include "Box2D\Box2D.h"
#include "SDL.h"
#include "SDL_ttf.h"
class Ball
{

public:
	//constructor that takes a rect as an input and initialiases all other variables except col
	/*Ball(Rect r) :rect(r) {

	};*/


	Ball();
	~Ball();

	SDL_Renderer* renderer;

	SDL_Surface* ball;
	b2Body* ballBody;
	b2BodyDef ballBodyDef;
	b2Vec2 ballVector;

	SDL_Texture* texture;

	//Ball class member variable
	bool m_contacting;

	int m_numContacts;

	bool play = false;


	//void Render(Renderer & r);

	void Init();

	Ball* getBall();

	bool Play();

	bool getTestBool();

	SDL_Texture* getTexture();

	void Update(unsigned int deltaTime);


	void Update(SDL_Renderer*);

	//Ball class functions
	//void startContact() { m_contacting = true; }
	//void endContact() { m_contacting = false; }
	//new implementation for contact state change
	void startContact() { m_numContacts++; }
	void endContact() { m_numContacts--; }



};

