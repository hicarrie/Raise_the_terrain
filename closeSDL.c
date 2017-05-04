#include "terrain.h"

void closeSDL(SDL_Window *gWindow, SDL_Renderer *gRenderer)
{
	/* destroy window */
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gRenderer = NULL;
	gWindow = NULL;

	/* quit SDL subsystems */
	IMG_Quit();
	SDL_Quit();
}
