#include "Library.h"

Library *library = new Library;

int main()
{


	gameObject testi;
	library->objs->add(&testi);
	testi.setX(50);
	testi.setY(50);

	library->logError(std::cout,"Heh");
	SDL_Texture* texture = library->loadTexture("data/texture.png");	

	SDL_RenderClear(library->renderer);
	testi.setTexture(texture);

	do
	{
		library->objs->gCurrent()->data->draw(library->renderer);
	} while(library->objs->adv());

	SDL_RenderPresent(library->renderer);
	SDL_Delay(2000);
	return 0;


}
