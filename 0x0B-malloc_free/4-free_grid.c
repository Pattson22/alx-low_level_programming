#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * free_grid - a function that frees a 2 dimensional grid
 * @grid: 2 dimension grid
 * @height: height dimension of grid
 * Description: a function that frees a 2 dimensional grid
 * Return: Always 0
 *
 */
void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}
