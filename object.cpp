#include "Library.h"
extern Library library;

gameObject::gameObject()
{
	x = y = h = w = 10;
}

gameObject::~gameObject()
{

}

int gameObject::setTexture(SDL_Texture* tex)
{
	txt=tex;
}

int gameObject::draw(SDL_Renderer *ren)
{
	SDL_Rect dst;
	dst.x=x;
	dst.y=y;
	dst.w=w;
	dst.h=h;
	SDL_RenderCopy(ren, txt, NULL, &dst);
}

int gameObject::update()
{

}
