#pragma once
#include <vector>
#include "Renderer.h"
#include <iostream>

class MapLoader
{
public:
	MapLoader();
	void Init();
	std::vector<SDL_Rect> getFloorTiles() { return m_floorTiles; }
	std::vector<SDL_Rect> getWallTiles() { return m_wallTiles; }

	//void Draw(sf::RenderWindow* window);
	//std::vector<sf::Sprite> getSprites() { return m_sprites; }
//	std::vector<sf::Sprite> getWallSprites() { return m_wallSprites; }
//	std::vector<sf::Vector2f> getSpawnPoints() { return m_spawnPoints; }
//	std::vector<sf::Vector2f>* getNodes() { return &m_nodes; }

private:
	std::vector<int> m_row0 = { 1,1,1,1,1,1,1,1,1,1 };
	std::vector<int> m_row1 = { 1,0,0,0,1,0,0,0,0,1 };
	std::vector<int> m_row2 = { 1,0,1,0,1,0,0,0,0,1 };
	std::vector<int> m_row3 = { 1,0,1,0,1,0,1,0,1,1 };
	std::vector<int> m_row4 = { 1,0,1,0,1,0,1,0,1,1 };
	std::vector<int> m_row5 = { 1,0,1,0,1,0,1,0,1,1 };
	std::vector<int> m_row6 = { 1,0,1,0,1,0,1,0,1,1 };
	std::vector<int> m_row7 = { 1,0,1,0,1,0,1,0,1,1 };
	std::vector<int> m_row8 = { 1,0,1,0,0,0,0,0,0,1 };
	std::vector<int> m_row9 = { 1,1,1,1,1,1,1,1,1,1 };

	std::vector<std::vector<int>> m_rows;

	std::vector<SDL_Point> m_nodes;

	SDL_Rect rect{ 0,0,50,50 };
	std::vector<SDL_Rect> m_floorTiles;
	std::vector<SDL_Rect> m_wallTiles;
};
