#include "terrain.h"

/* render window (global) */
SDL_Window *gWindow = NULL;

/* window renderer (global) */
SDL_Renderer *gRenderer = NULL;

/**
 * init - initializes SDL, window, and renderer
 * Return: True on success, False on failure
 */
bool init(void)
{
	/* initialization flag */
	bool success = true;

	/* initialize SDL */
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n",
		       SDL_GetError());
		success = false;
	}
	else
	{
		/* create window */
		gWindow = SDL_CreateWindow("Raise the Terrain",
					   SDL_WINDOWPOS_UNDEFINED,
					   SDL_WINDOWPOS_UNDEFINED,
					   SCREEN_WIDTH, SCREEN_HEIGHT,
					   SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n",
			       SDL_GetError());
			success = false;
		}
		else
		{
			/* create renderer for window */
			gRenderer = SDL_CreateRenderer(gWindow, -1,
						       SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer not created! SDL Error: %s\n",
				       SDL_GetError());
				success = false;
			}
			else
				/* initialize renderer color */
				SDL_SetRenderDrawColor(gRenderer, 0x2D, 0x4C,
						       0x76, 0xFF);
		}
	}
	return (success);
}

/**
 * main - main function for drawing grid
 * @argc: number of arguments
 * @argv: pointer to array of arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	unsigned int x1, y1, x2, y2, ix1, iy1, ix2, iy2;
	unsigned int i, j;
	SDL_Event event;

	/* start SDL and create window */
	if (!init())
		printf("Failed to initialize!\n");
	else
	{
		/* main loop flag */
		bool quit = false;

		while (!quit)
		{
			while (SDL_PollEvent(&event) != 0)
			{
				/* user requests quit */
				if (event.type == SDL_QUIT)
					quit = true;

				if (event.type == SDL_KEYDOWN &&
				    event.key.keysym.sym == SDLK_ESCAPE)
					quit = true;
			}

			/* clear screen */
			SDL_SetRenderDrawColor(gRenderer, 0x31, 0x5D,
					       0x5F, 0xFF);
			SDL_RenderClear(gRenderer);

			/* draw horizontal lines */
			SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF,
					       0xFF, 0xFF);
			x1 = SCREEN_WIDTH / 2;
			y1 = 0;
			for (i = 0; i < 8; i++)
			{
				for (j = 0; j < 7; j++)
				{
					ix1 = x1 - y1;
					iy1 = INCLINE * x1 + INCLINE * y1;
					x2 = x1 + LINE_LENGTH;
					y2 = y1;
					ix2 = x2 - y2;
					iy2 = INCLINE * x2 + INCLINE * y2;
					SDL_RenderDrawLine(gRenderer, ix1, iy1,
							   ix2, iy2);
					x1 = x2;
				}
				x1 = SCREEN_WIDTH / 2;
				y1 = y1 + LINE_LENGTH;
			}
			/* draw vertical lines */
			x1 = SCREEN_WIDTH / 2;
			y1 = 0;
			for (i = 0; i < 8; i++)
			{
				for (j = 0; j < 7; j++)
				{
					ix1 = x1 - y1;
					iy1 = INCLINE * x1 + INCLINE * y1;
					x2 = x1;
					y2 = y1 + LINE_LENGTH;
					ix2 = x2 - y2;
					iy2 = INCLINE * x2 + INCLINE * y2;
					SDL_RenderDrawLine(gRenderer, ix1, iy1,
							   ix2, iy2);
					y1 = y2;
				}
				y1 = 0;
				x1 = x1 + LINE_LENGTH;
			}
			/* update screen */
			SDL_RenderPresent(gRenderer);
		}
	}
	/* free resources and close SDL */
	closeSDL(gWindow, gRenderer);

	return (0);
}
