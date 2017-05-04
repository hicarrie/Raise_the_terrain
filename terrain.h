#ifndef TERRAIN_H
#define TERRAIN_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>

#define LINE_LENGTH 40
#define LINE_MAX 360

bool init();
void closeSDL(SDL_Window *window, SDL_Renderer *renderer);

#endif /* TERRAIN_H */
