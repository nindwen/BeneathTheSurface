#include "Library.h"
#include "actor.h"

int Actor::update()
{
	if(x != destinationX || y != destinationY)
	{
		listMap tOpen, tClosed;
		listMap* open;
		listMap* closed;
		open=&tOpen;
		closed=&tClosed;
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
							open->getNode(current->x+tx,current->y+ty)->parent=open->getNode(current->x,current->y);
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
				break;
			}
		}
		closed->print();
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
	}
	return 1;
}

void Actor::move(int x, int y)
{
	this->x+=x;
	this->y+=y;
}
