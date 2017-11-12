#include "Menu.h"

Menu::Menu(std::string &filePath, SDL_Renderer *r, bool tb)
{
	isDrawing = tb;
	std::cout << "MenuCreated";
	m_startMenuTexture = IMG_LoadTexture(r, filePath.c_str());

}

void Menu::Render(SDL_Renderer *r)
{
	//if (isDrawing)
		//r.drawImage(m_startMenuTexture);
}