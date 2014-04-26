#include "Library.h"
#include <cstdlib>

Tile::Tile()
{
	h = w = library->TILE_SIZE;
}

Level::Level(int n)
{
	level = new Tile*[library->LEVEL_SIZE];
	for (int i = 0; i < library->LEVEL_SIZE; i++)
	{
		level [i] = new Tile[library->LEVEL_SIZE+1];
	}
	int x,y;
	for(x=0;x<library->LEVEL_SIZE;x++)
		{
			for(y=0;y<library->LEVEL_SIZE;y++)
			{
				if(rand()%5==1)
				{
					level[x][y].Solid=true;
					level[x][y].setTexture(3);
					level[x][y].setX(x);
					level[x][y].setY(y);
				} else
				{
					level[x][y].Solid=false;
					level[x][y].setTexture(1);
					level[x][y].setX(x);
					level[x][y].setY(y);
				}
			}
		}
}


