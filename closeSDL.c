#include "terrain.h"

void closeSDL(SDL_Window *gWindow, SDL_Renderer *gRenderer)
{
	unsigned int i;

	/* free rows */
	/* for (i = 0; i < POINTS; i++)
	{
		free(rows[i]);
		} */

	/* destroy window */
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gRenderer = NULL;
	gWindow = NULL;

	/* quit SDL subsystems */
	SDL_Quit();
}
