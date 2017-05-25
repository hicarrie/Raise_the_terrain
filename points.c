#include "terrain.h"

/**
 * generate_rows - calculates points for lines drawn left to right and inclined
 * isometrically and stores in array of structs
 * Return: pointer to array of SDL_Point structs
 */
SDL_Point **generate_rows(void)
{
	unsigned int x, y, ix, iy;
	unsigned int i, j;
	SDL_Point **rows;
	SDL_Point *points;

	rows = malloc(sizeof(SDL_Point *) * POINTS);
	if (rows == NULL)
		return (-1);

	y = 0;
	for (i = 0; i < POINTS; i++)
	{
		points = malloc(sizeof(SDL_Point) * POINTS);
		if (points == NULL)
			return (-1);

		x = SCREEN_WIDTH / 2;
		for (j = 0; j < POINTS; j++)
		{
			ix = x - y;
			iy = INCLINE * x + INCLINE * y;
			points[j].x = ix;
			points[j].y = iy;
			x = x + LINE_LENGTH;
		}
		y = y + LINE_LENGTH;
		rows[i] = points;
	}

	/* print coordinates by row to check values */
	/* for (i = 0; i < POINTS; i++)
	 *{
	 *	printf("ROW %d\n", i);
	 *	for (j = 0; j < POINTS; j++)
	 *	{
	 *		printf("x: %d\ty: %d\n", rows[i][j].x, rows[i][j].y);
	 *	}
	 *}
	 */
	return (rows);
}

/**
 * generate_cols - calculates points for lines drawn top to bottom and inclined
 * isometrically and stores in array of structs
 * Return: pointer to array of SDL_Point structs
 */
SDL_Point **generate_cols(void)
{
	unsigned int x, y, ix, iy;
	unsigned int i, j;
	SDL_Point **cols;
	SDL_Point *points;

	cols = malloc(sizeof(SDL_Point *) * POINTS);
	if (cols == NULL)
		return (-1);

	x = SCREEN_WIDTH / 2;
	for (i = 0; i < POINTS; i++)
	{
		points = malloc(sizeof(SDL_Point) * POINTS);
		if (points == NULL)
			return (-1);

		y = 0;
		for (j = 0; j < POINTS; j++)
		{
			ix = x - y;
			iy = INCLINE * x + INCLINE * y;
			points[j].x = ix;
			points[j].y = iy;
			y = y + LINE_LENGTH;
		}
		x = x + LINE_LENGTH;
		cols[i] = points;
	}

	return (cols);
}
