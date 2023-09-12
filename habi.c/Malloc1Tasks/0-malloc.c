/*Write a function that creates an array of chars, and initializes it with a specific char.
• Prototype: char *create_array(unsigned int size, char c);
• Returns NULL if size = 0 • Returns a pointer to the array, or NULL if it fails*/

#include "main.h"
#include <stdlib.h>

/* *create_array  - Entry point
 * Description - 'a function that creates an array of chars
 * @size: size of the array
 * @c: char type
 * Return: pointer to char
*/

char *create_array(unsigned int size, char c)
{
    int i;  /*iterator for my upcomin for loop*/

    if (size == 0)
    {
        return (NULL);
    }

    char *array;
     array = malloc(sizeof(char) * size);

    if (array == 0)
    {
        return (NULL);
    }

    for (i = 0; i < size; i++)
    {
        array[i] = c;
    }

    array[i] = '\0';

    return (array);

}