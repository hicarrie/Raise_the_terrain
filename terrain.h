#ifndef TERRAIN_H
#define TERRAIN_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>

#define LINE_LENGTH 40
#define INCLINE .4

bool init();
void closeSDL(SDL_Window *window, SDL_Renderer *renderer);
unsigned int inclination(unsigned int coordinateX, unsigned int coordinateY, char xy);

#endif /* TERRAIN_H */
