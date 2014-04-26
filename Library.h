#ifndef _LIBRARY
#define _LIBRARY

#include <string>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "object.h"
#include "listObject.h"


class Library {
	public:
		Library();
		void logError(std::ostream &os, const std::string &msg);
		SDL_Texture* loadTexture(const std::string &file);

		int SCREEN_WIDTH;
		int SCREEN_HEIGHT;

		SDL_Renderer* renderer;
		SDL_Window* window;

		listObject* objs;

};

#endif
