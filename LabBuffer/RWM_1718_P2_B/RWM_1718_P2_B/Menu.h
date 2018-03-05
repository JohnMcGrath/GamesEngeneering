#pragma once

#include "SDL_image.h"
#include "Renderer.h"
#include <iostream>
#include "EventListener.h"

class Menu
{
public:
	Menu(std::string &filePath, SDL_Renderer *r,bool);
	void Render(SDL_Renderer *r);

	void Update(unsigned int deltaTime);
	void Init(std::string &filePath, SDL_Renderer *r);

	void setIsDrawing(bool newIsDrawing) { isDrawing = newIsDrawing; }
	void swapIsDrawing() { isDrawing = !isDrawing; }
	void onEvent(EventListener::Event);
	SDL_Texture * getTexture() { return m_startMenuTexture; }

private:
	SDL_Texture * m_startMenuTexture = nullptr;
	bool isDrawing;
	bool startedFirstTime = false;
};
