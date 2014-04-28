#include "Library.h"
#include "light.h"

float STEP = 4;

Light::Light(int x, int y)
{
	this->x=x;
	this->y=y;
	power=15;
	rpower=power;
	lightLevel=11;
}

int Light::update()
{

	if(rand()%90==1)
	{
		if(power==rpower)
		{
			power=rpower-1;
		}
		else
		{
			power=rpower;
		}
	}

	STEP=120.0/power;

	listMap* open = new listMap;
	listMap* closed = new listMap;
	listMap* walls = new listMap;
	nodeMap* newish = new nodeMap;
	newish->x=x;
	newish->y=y;
	newish->parent=nullptr;
	open->add(newish);
	open->first->G=110;

	while(1)
	{

		nodeMap* temp=open->first;
		nodeMap* low=open->first;
		while(1)
		{
			if(temp==nullptr) { break; }
			if(temp->G > low->G)
			{
				low=temp;
			}
			if(temp->next==nullptr)
			{
				break;
			}
			temp=temp->next;
		}
		nodeMap* current=low;
		if(current==nullptr)
		{
			break;
		}

		open->rm(current->x,current->y);
		closed->add(current);
		int leastOneFound=0;

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
					newish->G=current->G-STEP;
					leastOneFound=1;
				}
				else
				{
					if(open->getNode(current->x+tx,current->y+ty)->G > closed->getNode(current->x,current->y)->G-STEP)
					{
						open->getNode(current->x+tx,current->y+ty)->parent=closed->getNode(current->x,current->y);
						open->getNode(current->x+tx,current->y+ty)->G = closed->getNode(current->x,current->y)->G-STEP;
					}
				}
			}
			else if(library->currentlevel->level[current->x+tx][current->y+ty].Solid)
			{
				nodeMap* newish = new nodeMap;
				newish->x=current->x+tx;
				newish->y=current->y+ty;
				newish->parent=current;
				walls->add(newish);
				newish->G=110;//current->G;
			}
		}
		if(current->G==power)
		{
			//break;
		}

		if(!leastOneFound && closed->first==nullptr)
		{
			return 0;
		}
	}

	nodeMap* current=walls->last;
	while(1)
	{
		if(current->parent==nullptr) { break; }
		
		if(library->currentlevel->level[current->x][current->y].lightLevel<current->G/10)
		{
			library->currentlevel->level[current->x][current->y].lightLevel=current->G/10;
		}
		if(current->prev==nullptr) { break; }
		current=current->prev;
	}
	current=closed->last;
	while(1)
	{
		if(current->G>=0)
		{
			if(library->currentlevel->level[current->x][current->y].lightLevel<current->G/10)
			{
				library->currentlevel->level[current->x][current->y].lightLevel=current->G/10;
			}
		}
		if(current->prev==nullptr)
		{
			break;
		}
		current=current->prev;
	}
	delete open;
	delete closed;
	delete walls;
	return 1;
}




