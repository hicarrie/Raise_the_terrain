#include "terrain.h"

/**
 * closeSDL - destroys SDL objects and frees malloc'd memory
 * @gWindow: SDL Window
 * @gRenderer: SDL Renderer
 * @rows: array of structs for row points
 * @cols: array of structs for col points
 * Return: void
 */
void closeSDL(SDL_Window *gWindow, SDL_Renderer *gRenderer,
	      SDL_Point **rows, SDL_Point **cols)
{
	int i;

	/* free malloc'd space for points */
	for (i = 0; i < POINTS; i++)
	{
		free(rows[i]);
		free(cols[i]);
	}

	free(rows);
	free(cols);

	/* destroy window */
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gRenderer = NULL;
	gWindow = NULL;

	/* quit SDL subsystems */
	SDL_Quit();
}
