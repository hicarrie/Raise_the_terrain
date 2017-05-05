#ifndef TERRAIN_H
#define TERRAIN_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>

#define LINE_LENGTH 20
#define LINE_MAX 180

bool init();
void closeSDL(SDL_Window *window, SDL_Renderer *renderer);

#endif /* TERRAIN_H */
