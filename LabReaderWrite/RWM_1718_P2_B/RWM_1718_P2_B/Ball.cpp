#pragma once

#include "Ball.h"
#include "SDL.h"
using namespace std;
#include <iostream>

Ball::Ball()
{
	m_contacting = false;
	m_numContacts = 0;
	
}

Ball::~Ball()
{
}

void Ball::Init()
{


	m_numContacts = 0;
}


Ball* Ball::getBall()
{
	return this;
}
