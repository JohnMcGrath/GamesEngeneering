#pragma once
#include "SDL.h"
#include "SDL_image.h"

class Enemy
{
public:
	Enemy(SDL_Renderer* r);
	void Update();
	void Render();

private:
	SDL_Texture * m_texture;
	SDL_Point m_pos;
	SDL_Point m_velocity;
	SDL_Point m_target;

	SDL_Rect tempRect;

	SDL_Renderer* m_rend;
};
