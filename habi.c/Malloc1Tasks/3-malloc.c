/** Write a function that returns a pointer to a 2 dimensional array of integers.
• Prototype: int **alloc_grid(int width, int height);
• Each element of the grid should be initialized to 0 • The function should return NULL on failure
• If width or height is 0 or negative, return NULL
*/

/**
 * alloc_grid - Entry point
 * @width : width of grid
 * @height : height of grid
 * Return: pointer to 2 dimensional array
*/

#include "main.h"
#include <stdlib.h>

int **alloc_grid(int width, int height)
{
    int **doublep;
    int h, j;

    if (width <= 0 || height <= 0)
    {
        return (NULL);
    }

    doublep = (int**) malloc(height * sizeof(int*));

    if (doublep == NULL)
    {
        return (NULL);
    }

for (h = 0; h < height; h++)
{
    doublep[h] = (int *) malloc(width *sizeof(int));

    if (doublep[h] == NULL)
    {
        for (j = 0; j < h; j++)
        {
            free(doublep[j]);
        }
        free(doublep);
        return (NULL);
    }

    for (j = 0; j < width; j++)
    {
        doublep[h][j] = 0;
    }
}
return (doublep);
}