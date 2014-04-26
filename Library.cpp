#include "Library.h"
extern Library library;

Library::Library()
{
	SCREEN_WIDTH=600;
	SCREEN_HEIGHT=300;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		logError(std::cout, "SDL_Init");
	}

	window = SDL_CreateWindow("Lesson 3", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr){
		logError(std::cout, "CreateWindow");
		SDL_Quit();
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr){
		logError(std::cout, "CreateRenderer");
		SDL_Quit();
	}

	objs = new listObject();
}

void Library::logError(std::ostream &os, const std::string &msg)
{
	os << msg << " error: " << SDL_GetError() << std::endl;
}

SDL_Texture* Library::loadTexture(const std::string &file) 
{
	SDL_Texture *texture = IMG_LoadTexture(renderer, file.c_str());
	if (texture == nullptr){	
		logError(std::cout, "LoadTexture");
	}
	return texture;
}
