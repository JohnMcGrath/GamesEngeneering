#include "Renderer.h"

Renderer::Renderer()
{
	gameWindow = SDL_CreateWindow("Ambush", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	gameRenderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawColor(gameRenderer, 200, 200, 200, 255);

	m_floorTexture = IMG_LoadTexture(gameRenderer, "ASSETS/blueSquare.png");
	m_wallTexture = IMG_LoadTexture(gameRenderer, "ASSETS/blackSquare.png");
}
void Renderer::Render()
{


	SDL_RenderPresent(gameRenderer);
}

void Renderer::DrawTiles(std::vector<SDL_Rect> floorTiles, std::vector<SDL_Rect> wallTiles)
{
	// clear the screen
	SDL_RenderClear(gameRenderer);

	for (int i = 0; i < floorTiles.size(); i++)
	{
		//Copy to the renderer
		SDL_RenderCopy(gameRenderer, m_floorTexture, nullptr, &floorTiles.at(i));
	}

	for (int i = 0; i < wallTiles.size(); i++)
	{
		//Copy to the renderer
		SDL_RenderCopy(gameRenderer, m_wallTexture, nullptr, &wallTiles.at(i));
	}

	SDL_RenderPresent(gameRenderer);
}