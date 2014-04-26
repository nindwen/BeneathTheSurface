#include "Library.h"

Library *library = new Library;

int main()
{
	gameObject testi;
	library->objs->add(&testi);
	testi.setX(2);
	testi.setY(3);

	library->logError(std::cout,"Heh");
	int texture = library->loadTexture("data/texture.png");	
	library->loadTexture("data/jokutiili.png");
	library->loadTexture("data/mursu.png");

	SDL_RenderClear(library->renderer);
	testi.setTexture(texture);

	Level *level = new Level(1);
	library->currentlevel=level;
	
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
		library->objs->gCurrent()->data->draw(library->renderer);
	} while(library->objs->adv());

	SDL_RenderPresent(library->renderer);
	SDL_Delay(2000);
	return 0;
}
