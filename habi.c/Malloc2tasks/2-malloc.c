/**
 * Write a function that allocates memory for an array, using malloc.
 * • Prototype: void *_calloc(unsigned int nmemb, unsigned int size);
 * • The _calloc function allocates memory for an array of nmemb elements of size bytes
 *  each and returns a pointer to the allocated memory.
 * • The memory is set to zero
 * • If nmemb or size is 0, then _calloc returns NULL
 * • If malloc fails, then _calloc returns NULL
 */

#include "main.h"
#include <stdlib.h>

/**
 * _calloc - Entry point
 * Description - 'a function allocating memory using malloc'
 * @nmemb: array of elements
 * @size: number of bytes of each element
 * Return: void
 */

void *_calloc(unsigned int nmemb, unsigned int size) {
    char *storer;
    unsigned int h;

    /* If nmemb or size is 0, then _calloc returns NULL */
    if (nmemb == 0 || size == 0) {
        return (NULL);
    }
    /*The _calloc function allocates memory for an array of nmemb elements of size bytes*/
    storer = malloc(nmemb * size);

    /* If malloc fails, then _calloc returns NULL*/
    if (storer == 0) {
        return (NULL);
    }
    /*The memory is set to zero with a for loop*/

    for (h = 0; h < (nmemb * size); h++) {
        storer[h] = 0;
    }
    return (storer);
}