#ifndef TERRAIN_H
#define TERRAIN_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>

/* screen dimensions */
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 960
#define LINE_LENGTH 80
#define INCLINE .4

bool init();
void closeSDL(SDL_Window *window, SDL_Renderer *renderer);
unsigned int inclination(unsigned int coordinateX, unsigned int coordinateY, char xy);

#endif /* TERRAIN_H */
