#ifndef _LIBRARY
#define _LIBRARY

#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "object.h"
#include "listObject.h"
#include "listMap.h"
#include "level.h"
#include "actor.h"

//extern Library *library;

class Library {
	public:
		Library();
		void logError(std::ostream &os, const std::string &msg);
		int loadTexture(const std::string &file);

		int SCREEN_WIDTH;
		int SCREEN_HEIGHT;
		int TILE_SIZE;
		int LEVEL_SIZE;
		int CAMERA_SPEED;

		SDL_Texture *textures[50];
		int texIndex;

		int cameraX, cameraY;

		SDL_Renderer* renderer;
		SDL_Window* window;

		listObject* objs;

		Level *currentlevel;

};
extern Library *library;

#endif
