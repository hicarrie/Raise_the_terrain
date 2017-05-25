#ifndef TERRAIN_H
#define TERRAIN_H

#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>

/* screen dimensions */
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 960

#define POINTS 8
#define LINE_LENGTH 80
#define INCLINE .4

bool init(void);
void closeSDL(SDL_Window *window, SDL_Renderer *renderer,
	      SDL_Point **rows, SDL_Point **cols);

SDL_Point **generate_rows(void);
SDL_Point **generate_cols(void);

#endif /* TERRAIN_H */
