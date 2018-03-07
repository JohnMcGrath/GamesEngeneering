#pragma once

#include "Contact.h"
#include <iostream>


Contact::Contact()
{
	m_numContacts = 0;
}

Contact::~Contact()
{
}

bool Contact::Play()
{
	return 0;
}
void Contact::Init()
{
	m_numContacts = 0;
}

void Contact::BeginContact(b2Contact* contact)
{
	m_numContacts++;
	std::cout << "contact" << std::endl;
	std::cout << "no: " << m_numContacts << std::endl;
	//check if fixture A was a ball
	void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
	if (bodyUserData)
		static_cast<Ball*>(bodyUserData)->startContact();


	//check if fixture B was a ball
	bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
	if (bodyUserData)
		static_cast<Ball*>(bodyUserData)->startContact();

	m_audio.SfxPlay();
}

void Contact::EndContact(b2Contact* contact)
{

	m_numContacts--;
	std::cout << "end contact" << std::endl;
	std::cout << "no: " << m_numContacts << std::endl;
	//check if fixture A was a ball
	void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
	if (bodyUserData)
		static_cast<Ball*>(bodyUserData)->endContact();

	//check if fixture B was a ball
	bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
	if (bodyUserData)
		static_cast<Ball*>(bodyUserData)->endContact();



}

