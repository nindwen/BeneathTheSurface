#include "Library.h"

gameObject::gameObject()
{
	x = y =0;
	h = w = library->TILE_SIZE;
	moving=0;
	speed=0;
	dx=dy=0;
	lightLevel=12;
}

gameObject::~gameObject()
{

}

int gameObject::draw(SDL_Renderer *ren)
{
	//Highlight
	int xx,xy;
	SDL_GetMouseState(&xx,&xy);
	xx-=library->cameraX;
	xy-=library->cameraY;
	if( (xx>=this->x*library->TILE_SIZE && xx<=this->x*library->TILE_SIZE+library->TILE_SIZE) && (xy>=this->y*library->TILE_SIZE && xy<= this->y*library->TILE_SIZE+library->TILE_SIZE))
	{
		lightLevel=12;
	}

	SDL_Rect dst;
	dst.x=x*library->TILE_SIZE+library->cameraX+(float)dx;
	dst.y=y*library->TILE_SIZE+library->cameraY+(float)dy;
	dst.w=w;
	dst.h=h;
	SDL_SetTextureColorMod(library->textures[texIndex],lightLevel*255/12,lightLevel*255/12-lightLevel*5,lightLevel*255/12-lightLevel*5);
	SDL_RenderCopy(ren, library->textures[texIndex], NULL, &dst);
	return 1;
}

int gameObject::update()
{
	return 1;

}
