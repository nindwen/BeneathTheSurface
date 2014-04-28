#include "Library.h"

gameObject::gameObject()
{
	x = y =0;
	h = w =40;
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
