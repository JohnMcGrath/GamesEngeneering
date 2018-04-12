#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include <vector>

const int SCREEN_FPS = 60;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

class Renderer
{
public:
	Renderer();
	void Render();

	void DrawTiles(std::vector<SDL_Rect> floorTiles, std::vector<SDL_Rect> wallTiles);
	SDL_Renderer* getRenderer() { return gameRenderer; }

	private:
		SDL_Window* gameWindow;
		SDL_Renderer* gameRenderer;

		SDL_Texture * m_floorTexture;
		SDL_Texture * m_wallTexture;
};
