#include "Library.h"

Library *library = new Library;

int main()
{

	int texture = library->loadTexture("data/texture.png");	
	library->loadTexture("data/jokutiili.png");
	library->loadTexture("data/mursu.png");

	SDL_RenderClear(library->renderer);

	Level *level = new Level(1);
	library->currentlevel=level;

	Actor testi(3,3);
	library->objs->add(&testi);
	if(!testi.setDestination(23,23))
	{
		std::cout << "pröl";
	}

	Actor testi2(12,12);
	library->objs->add(&testi2);
	if(!testi2.setDestination(6,19))
	{
		std::cout << "pril";
	}
	testi.setTexture(texture);
	testi2.setTexture(texture);
	int valotek=library->loadTexture("data/valo.png");

	Light valo1(5,3);
	Light valo2(12,1);
	Light valo3(23,23);
	Light valo4(6,19);
	valo1.setTexture(valotek);
	valo2.setTexture(valotek);
	valo3.setTexture(valotek);
	valo4.setTexture(valotek);
/*	library->objs->add(&valo1);
	library->objs->add(&valo2);
	library->objs->add(&valo3);
	library->objs->add(&valo4);
*/
  bool quit=false;
	while(!quit)
	{
		library->lClicked=false;
		library->rClicked=false;

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
					case SDLK_SPACE:
						library->TILE_SIZE-=10;
						break;
					case SDLK_PLUS:
						library->TILE_SIZE+=10;
						break;
					default:
						break;
				} 
			}
			else if(e.type == SDL_MOUSEBUTTONUP)
			{
				if(e.button.button == SDL_BUTTON_LEFT)
				{
					library->lClicked=true;
				}
				else if(e.button.button == SDL_BUTTON_RIGHT)
				{
					library->rClicked=true;
				}
			}
		}

		SDL_RenderClear(library->renderer);

		//Draw current level
		int x,y;
		for(x=0;x<library->LEVEL_SIZE;x++)
		{
			for(y=0;y<library->LEVEL_SIZE;y++)
			{
				library->currentlevel->level[x][y].draw(library->renderer);
				library->currentlevel->level[x][y].update();
			}
		}

		//gameObject loop
		do
		{
			library->objs->gCurrent()->data->update();
			library->objs->gCurrent()->data->draw(library->renderer);
		} while(library->objs->adv());

		SDL_RenderPresent(library->renderer);
	}
	return 0;
}
