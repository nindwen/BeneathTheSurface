#include "Library.h"

Library *library = new Library;

int main()
{
	Actor testi;
	library->objs->add(&testi);
	testi.setX(3);
	testi.setY(3);
	testi.setDestination(8,8);

	Actor testi2;
	library->objs->add(&testi2);
	testi2.setX(8);
	testi2.setY(4);
	testi2.setDestination(12,12);

	library->logError(std::cout,"Heh");
	int texture = library->loadTexture("data/texture.png");	
	library->loadTexture("data/jokutiili.png");
	library->loadTexture("data/mursu.png");

	SDL_RenderClear(library->renderer);
	testi.setTexture(texture);
	testi2.setTexture(texture);

	Level *level = new Level(1);
	library->currentlevel=level;
  bool quit=false;
	while(!quit)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			else if( e.type == SDL_KEYDOWN ) 
			{ //Select surfaces based on key press 
				switch( e.key.keysym.sym ) 
				{
					case SDLK_UP:
						library->cameraY+=library->CAMERA_SPEED;
						break;
					case SDLK_DOWN:
						library->cameraY-=library->CAMERA_SPEED;
						break;
					case SDLK_LEFT:
						library->cameraX+=library->CAMERA_SPEED;
						break;
					case SDLK_RIGHT:
						library->cameraX-=library->CAMERA_SPEED;
						break;
					default:
						break;
				} 
			}
		}


		SDL_RenderClear(library->renderer);
		int x,y;
		for(x=0;x<library->LEVEL_SIZE;x++)
		{
			for(y=0;y<library->LEVEL_SIZE;y++)
			{
				library->currentlevel->level[x][y].draw(library->renderer);
			}
		}

		do
		{
			library->objs->gCurrent()->data->update();
			library->objs->gCurrent()->data->draw(library->renderer);
		} while(library->objs->adv());

		SDL_RenderPresent(library->renderer);
		SDL_Delay(20);
	}
	return 0;
}
