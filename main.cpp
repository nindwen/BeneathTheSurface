#include "Library.h"

Library *library = new Library;

int main()
{
	Actor testi;
	library->objs->add(&testi);
	testi.setX(2);
	testi.setY(3);
	testi.setDestination(4,7);

	library->logError(std::cout,"Heh");
	int texture = library->loadTexture("data/texture.png");	
	library->loadTexture("data/jokutiili.png");
	library->loadTexture("data/mursu.png");

	SDL_RenderClear(library->renderer);
	testi.setTexture(texture);

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
		}
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
			//library->objs->gCurrent()->data->update();
			library->objs->gCurrent()->data->draw(library->renderer);
		} while(library->objs->adv());

		SDL_RenderPresent(library->renderer);
		SDL_Delay(20);
	}
	return 0;
}
