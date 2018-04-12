#include "MapLoader.h"

MapLoader::MapLoader()
{
	m_rows.push_back(m_row0);
	m_rows.push_back(m_row1);
	m_rows.push_back(m_row2);
	m_rows.push_back(m_row3);
	m_rows.push_back(m_row4);
	m_rows.push_back(m_row5);
	m_rows.push_back(m_row6);
	m_rows.push_back(m_row7);
	m_rows.push_back(m_row8);
	m_rows.push_back(m_row9);

	for (int i = 0; i < m_row0.size(); i++)
	{
		std::cout << "" << std::endl;
		//Height
		for (int j = 0; j < m_rows.size(); j++)
		{
			if (m_rows.at(i).at(j) == 1)
			{
				//Draw a wall
				std::cout << "||";

				rect.x = 50 * j;
				rect.y = 50 * i;
				m_wallTiles.push_back(rect);
			}

			else 
			{
				//Draw a floor
				std::cout << "  ";

				rect.x = 50 * j;
				rect.y = 50 * i;
				m_floorTiles.push_back(rect);

				//Add a node
				m_nodes.push_back(SDL_Point{ (50 * j) + 25, (50 * i) + 25 });
			}

		}
	}
}