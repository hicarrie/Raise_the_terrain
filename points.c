#include "terrain.h"

/**
 * generate_rows - calculates points for lines drawn left to right then inclined
 * isometrically and stores in array of structs
 * Return: pointer to array of SDL_Point structs
 */
SDL_Point **generate_rows(void)
{
	unsigned int x, y, ix, iy;
	unsigned int i, j;
	SDL_Point **rows;
        SDL_Point *points;

	y = 0;
	for (i = 0; i < POINTS; i++)
	{
		*rows = malloc(sizeof(SDL_Point) * POINTS * POINTS);
		if (*rows == NULL)
			return (-1);

		points = malloc(sizeof(SDL_Point) * POINTS);
		if (points == NULL)
			return (-1);

		x = SCREEN_WIDTH / 2;
		y = y + LINE_LENGTH;
		for (j = 0; j < POINTS; j++)
		{
			ix = x - y;
			iy = INCLINE * x + INCLINE * y;
			points[j].x = ix;
			points[j].y = iy;
			x = x + LINE_LENGTH;
		}
		rows[i] = points;
	}

	for (i = 0; i < POINTS; i++)
	{
		printf("ROW %d\n", i);
		for (j = 0; j < POINTS; j++)
		{
			printf("x: %d\ty: %d\n", rows[i][j].x, rows[i][j].y);
		}
	}

	return (*rows);
}

/**
 * pointsB - calculates points for lines drawn left to right then inclined
 * isometrically and stores in array of structs
 * Return: pointer to array of SDL_Point structs
 */
/*
unsigned int *pointsB()
{
	unsigned int x1, y1, x2, y2, ix1, iy1, ix2, iy2;
	unsigned int i, j;
        SDL_Point *points;

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

	return (points);
}
*/
