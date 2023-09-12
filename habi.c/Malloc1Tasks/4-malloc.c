/** Write a function that frees a 2 dimensional grid previously created by your alloc_grid function.
• Prototype: void free_grid(int **grid, int height);
• Note that we will compile with your alloc_grid.c file. Make sure it compiles.
*/

#include "main.h"
#include <stdlib.h>

/**
 * free_grid - Entry point
 * Description - 'a function that frees the memory space allocated for previous program'
 * @grid : pointer to 2 dimensional array
 * @height ; height of grid
 * Return: void
*/

void free_grid(int **grid, int height)
{
    int h;

    for (h = 0; h < height; h++)
    {
        free(grid[h]);
    }
    free(grid);
}


