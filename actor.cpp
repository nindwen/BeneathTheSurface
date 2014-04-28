#include "Library.h"
#include "actor.h"
#include "level.h"

int Actor::update()
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
	return 1;

}

void Actor::move(int x, int y)
{
	this->x+=x;
	this->y+=y;
}
