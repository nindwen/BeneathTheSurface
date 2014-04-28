#include "Library.h"
#include "actor.h"
#include "level.h"

Actor::Actor(int x, int y)
{
	this->x=x;
	this->y=y;
	destinationX=x;
	destinationY=y;

	moving=0;
	speed=5;
	dx=dy=0;
}

int Actor::update()
{
	if(moving)
	{
		if(dx==0 && dy==0)
		{
			moving=0;
		}
		else
		{
			if(dx!=0) { 
				if(dx<0) { dx+=speed; }
				else { dx-=speed; }
			}
			if(dy!=0) { 
				if(dy<0) {dy+=speed; }
				else { dy-=speed; }
			}
		}
	}
	else
	{
		if(x != destinationX || y != destinationY)
		{
			listMap* closed = library->currentlevel->findPath(x,y,destinationX,destinationY);
			if(closed==nullptr)
			{
				return 0;
			}
			nodeMap* temp = closed->first;
			while(1)
			{
				if(temp->parent->x==x && temp->parent->y==y)
				{
					move(temp->x-x,temp->y-y);
					return 1;
				}
				temp=temp->parent;
			}
			delete closed;
		}
	}
	return 1;
}

void Actor::move(int x, int y)
{
	this->x+=x;
	this->y+=y;
	dx-=40*x;
	dy-=40*y;
	moving=1;
} 

int Actor::setDestination(int x, int y)
{ 
	if(library->currentlevel->level[x][y].Solid || (x==0 || y==0) || (x==library->LEVEL_SIZE-1 || y==library->LEVEL_SIZE-1) )
	{
		return 0;
	}
	destinationX=x; 
	destinationY=y; 
	return 1;
}
