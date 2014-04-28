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
	lightLevel=12;

	selected=false;
}

int Actor::update()
{
	if(library->lClicked)
	{
		int x,y;
		SDL_GetMouseState(&x,&y);
		x-=library->cameraX;
		y-=library->cameraY;

		if( (x>=this->x*library->TILE_SIZE && x<=this->x*library->TILE_SIZE+library->TILE_SIZE) && (y>=this->y*library->TILE_SIZE && y<= this->y*library->TILE_SIZE+library->TILE_SIZE))
		{
			selected=true;
			library->lClicked=false;
		}
		else 
		{
			selected=false;
		}
	}
	if(library->rClicked && selected)
	{
		int x,y;
		SDL_GetMouseState(&x,&y);
		x-=library->cameraX;
		y-=library->cameraY;

		selected=false;

		setDestination(x/library->TILE_SIZE,y/library->TILE_SIZE);
	}
		

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
		//If we are not moving and are not ind destination, search path
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
	//Smooth movement-stuff:
	dx-=library->TILE_SIZE*x;
	dy-=library->TILE_SIZE*y;
	moving=1;

	//Update lightleve
	lightLevel=library->currentlevel->level[this->x][this->y].lightLevel;
} 

int Actor::setDestination(int x, int y)
{ 
	//If accesible
	if(library->currentlevel->level[x][y].Solid || (x==0 || y==0) || (x==library->LEVEL_SIZE-1 || y==library->LEVEL_SIZE-1) )
	{
		return 0;
	}
	destinationX=x; 
	destinationY=y; 
	return 1;
}
