#pragma once

#include "Box2D\Box2D.h"
#include "Ball.h"
#include "Audio.h"

class Contact : public b2ContactListener
{

public:


	Contact();
	~Contact();

	bool Play();

	void Init();

	virtual void BeginContact(b2Contact* contact);

	// Called when two fixtures cease to touch
	virtual void EndContact(b2Contact* contact);

	int m_numContacts = 0;
	//b2Contact
	// Get the first fixture in this contact
	b2Fixture* GetFixtureA();

	// Get the second fixture in this contact
	b2Fixture* GetFixtureB();

	Audio m_audio;

};

