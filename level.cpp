#include "Library.h"
#include <cstdlib>

Tile::Tile()
{
	h = w = library->TILE_SIZE;
	lightLevel=1;
}

int Tile::update()
{
	lightLevel=1;
	return 1;
}

Level::Level(int n)
{

	roomCount = 7;
	rMinSize = 5;
	rMaxSize = 12;

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
			
				level[x][y].Solid=true;
				level[x][y].setTexture(2);
				level[x][y].setX(x);
				level[x][y].setY(y);
			}
		}
	Room rooms[roomCount];
	int i,j;	
	for(i=0;i<roomCount;i++)
		{
		for(j=0;j<roomCount;j++)
			{
				if(rooms[i].roomsCollide(rooms[j])==true && i != j)
					{
						std::cout << "Collision with rooms " << i << " and " << j << "\n";
rooms[i] = Room();
i = 0;
j = 0;
					} 
			}
		}


	for(i=0;i<roomCount;i++)
		{
			for(x=1;x<rooms[i].w-1;x++)
				{
					for(y=1;y<rooms[i].h-1;y++)
						{
							level[rooms[i].x+x][rooms[i].y+y].setTexture(1);
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

	delete open;
	return closed;
}

Room::Room() {
	w = rand()%7+5;
	h = rand()%7+5;
	x = rand()%(library->LEVEL_SIZE-w);
	y = rand()%(library->LEVEL_SIZE-h);
	//roomCount ++;
}

Room::Room(int xValue, int yValue, int width, int height) {
	x = xValue;
	y = yValue;
	w = width;
	h = height;
	//roomCount ++;
}

bool Room::roomsCollide(Room room) {
	if(((this->x>=room.x && this->x-room.x<room.w-1) || (this->x<room.x && room.x-this->x<this->w-1)) && ((this->y>=room.y && this->y-room.y<room.h-1) || (this->y<room.y && room.y-this->y<this->h-1))) {return true;}
	else{return false;}
}
