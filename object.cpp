#include "Library.h"

gameObject::gameObject()
{
	x = y =0;
	h = w =40;
}

gameObject::~gameObject()
{

}

int gameObject::draw(SDL_Renderer *ren)
{
	SDL_Rect dst;
	dst.x=x*library->TILE_SIZE;
	dst.y=y*library->TILE_SIZE;
	dst.w=w;
	dst.h=h;
	SDL_RenderCopy(ren, library->textures[texIndex], NULL, &dst);
	return 1;
}

int gameObject::update()
{
	return 1;

}
