#include "Library.h"
#include "actor.h"

int Actor::update()
{
	if(x != destinationX && y != destinationY)
	{
		listMap *open;
		listMap *closed;
		open->add(x,y,x,y);
		open->first->G=0;
		open->setValues(x,y,destinationX,destinationY);

		while(1)
		{
			int leastOneFound=0;
			nodeMap *current = open->lowestF();
			open->rm(current->x,current->y);
			closed->add(current->x,current->y,current->parent->x,current->parent->y);

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

				if(library->currentlevel->level[current->x+tx][current->y+ty].Solid 
						&& closed->getNode(current->x+tx,current->y+ty) == nullptr)
				{
					if(open->getNode(current->x+tx,current->y+ty) == nullptr)
					{
						open->add(current->x+tx,current->y+ty,current->x,current->y);
						open->setValues(current->x+tx,current->y+ty, destinationX, destinationY);
						leastOneFound=1;
					}
					else
					{
						if(open->getNode(current->x+tx,current->y+ty)->G > open->getNode(current->x,current->y)->G+1)
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
		nodeMap* temp = closed->last;
		while(1)
		{
			if(temp->parent->x==destinationX && temp->parent->y==destinationY)
			{
				move(temp->x-x,temp->y-y);
			}
			temp=temp->parent;
		}
	}
}

void Actor::move(int x, int y)
{
	this->x+=x;
	this->y+=y;
}
