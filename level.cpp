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
					level[x][y].setTexture(2);
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


listMap* Level::findPath(int x, int y, int destinationX, int destinationY)
{
	listMap* open = new listMap;
	listMap* closed = new listMap;
	nodeMap* newish = new nodeMap;
	newish->x=x;
	newish->y=y;
	newish->parent=nullptr;
	open->add(newish);
	open->first->G=0;
	open->setValues(x,y,destinationX,destinationY);

	open->print();

	while(1)
	{
		int leastOneFound=0;
		nodeMap *current = open->lowestF();
		open->rm(current->x,current->y);
		closed->add(current);

		int ty,tx;
		for(int i=0;i<4;i++)
		{
			switch(i)
			{
				case 0:
					ty=-1;
					tx=0;
					break;
				case 1:
					ty=1;
					tx=0;
					break;
				case 2:
					ty=0;
					tx=-1;
					break;
				case 3:
					ty=0;
					tx=1;
					break;
			}

			if( (current->x==0 || current->y==0) || (current->x==library->LEVEL_SIZE-1 || current->y==library->LEVEL_SIZE-1) )
			{
				break;
			}
			if(library->currentlevel->level[current->x+tx][current->y+ty].Solid == false
					&& closed->getNode(current->x+tx, current->y+ty) == nullptr)
			{
				if(open->getNode(current->x+tx,current->y+ty) == nullptr)
				{
					nodeMap* newish = new nodeMap;
					newish->x=current->x+tx;
					newish->y=current->y+ty;
					newish->parent=current;
					open->add(newish);
					open->setValues(current->x+tx,current->y+ty, destinationX, destinationY);
					leastOneFound=1;
				}
				else
				{
					if(open->getNode(current->x+tx,current->y+ty)->G > closed->getNode(current->x,current->y)->G+1)
					{
						open->getNode(current->x+tx,current->y+ty)->parent=closed->getNode(current->x,current->y);
						open->setValues(current->x+tx,current->y+ty,destinationX,destinationY);
					}
				}
			}
		}
		if(current->y == destinationY && current->x == destinationX)
		{
			break;
		}

		if(!leastOneFound && closed->first==nullptr)
		{
			return nullptr;
		}
	}

	return closed;
}
