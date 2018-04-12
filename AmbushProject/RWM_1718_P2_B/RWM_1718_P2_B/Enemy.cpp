#include "Enemy.h"

Enemy::Enemy(SDL_Renderer* r)
{
	tempRect.w = 40;
	tempRect.h = 40;

	tempRect.x = 400;
	tempRect.y = 400;

	m_rend = r;
	m_texture = IMG_LoadTexture(m_rend, "ASSET/enemy.png");
}

void Enemy::Update()
{
	//Movement
	/*

	m_velocity = t - m_pos;
	m_velocity = Normalise(m_velocity);
	m_velocity * m_maxSpeed;

	*/
}

void Enemy::Render()
{
	//SDL_RenderCopy(m_rend, m_texture, nullptr, &tempRect);

	//SDL_RenderPresent(m_rend);
}