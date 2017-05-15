#include "terrain.h"

/**
 * closeSDL - frees resources and close SDL
 * @gWindow: SDL window
 * @gRenderer: renderer
 * Return: void
 */
void closeSDL(SDL_Window *gWindow, SDL_Renderer *gRenderer)
{
	unsigned int i;

	/* destroy window */
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gRenderer = NULL;
	gWindow = NULL;

	/* quit SDL subsystems */
	SDL_Quit();
}
