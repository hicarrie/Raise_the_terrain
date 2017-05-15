#include "terrain.h"

/* render window (global) */
SDL_Window *gWindow = NULL;

/* window renderer */
SDL_Renderer *gRenderer = NULL;

bool init()
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
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				/* initialize renderer color */
				SDL_SetRenderDrawColor(gRenderer, 0x2D, 0x4C, 0x76, 0xFF);
			}
		}
	}
	return success;
}

int main(int argc, char *argv[])
{
	unsigned int x1, y1, x2, y2, ix1, iy1, ix2, iy2;
	unsigned int i, j;

	/* start SDL and create window */
	if (!init())
		printf("Failed to initialize!\n");
	else
	{
		/* main loop flag */
		bool quit = false;

		/* event handler */
		SDL_Event e;

			/* clear screen */
			SDL_SetRenderDrawColor(gRenderer, 0x31, 0x5D, 0x5F, 0xFF);
			SDL_RenderClear(gRenderer);

			/* draw / lines */
			SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
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
					SDL_RenderDrawLine(gRenderer, ix1, iy1, ix2, iy2);
					x1 = x2;
				}
				x1 = SCREEN_WIDTH / 2;
				y1 = y1 + LINE_LENGTH;
			}

			/* draw \ lines */
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
					SDL_RenderDrawLine(gRenderer, ix1, iy1, ix2, iy2);
					y1 = y2;
				}
				y1 = 0;
				x1 = x1 + LINE_LENGTH;
			}

		/* while application is running */
		while (!quit)
		{
			/* handle events on queue */
			while (SDL_PollEvent(&e) != 0)
			{
				/* user requests quit */
				if (e.type == SDL_QUIT)
					quit = true;

				if (e.type == SDL_KEYDOWN && e.key.keysym.sym
				    == SDLK_ESCAPE)
					quit = true;
			}



			/* update screen */
			SDL_RenderPresent(gRenderer);
		}
	}

	/* free resources and close SDL */
	closeSDL(gWindow, gRenderer);

	return (0);
}
