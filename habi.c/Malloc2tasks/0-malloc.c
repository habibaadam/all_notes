/** Write a function that allocates memory using malloc.
 *• Prototype: void *malloc_checked(unsigned int b);
 *• Returns a pointer to the allocated memory
 *• if malloc fails, the malloc_checked function should cause normal process termination
 * with a status value of 98
 */

#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked - Entry point
 * @b : unsigned integer
 * Return : pointer to allocated memory
 */

void *malloc_checked(unsigned int b) {
    int *ptr;

    ptr = malloc(b);

    if (ptr == NULL) {
        exit(98);
    }

    return (ptr);
}
