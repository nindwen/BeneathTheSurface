#include "Library.h"

Library::Library()
{
	SCREEN_WIDTH=600;
	SCREEN_HEIGHT=600;
	TILE_SIZE=40;
	LEVEL_SIZE=15;
	texIndex=0;
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

int Library::loadTexture(const std::string &file) 
{
	SDL_Texture *texture = IMG_LoadTexture(renderer, file.c_str());
	if (texture == nullptr){	
		logError(std::cout, "LoadTexture");
	}
	textures[texIndex]=texture;
	return texIndex++;
}
