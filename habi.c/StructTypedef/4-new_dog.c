/**
 * Write a function that creates a new dog.
• Prototype: dog_t *new_dog(char *name, float age, char *owner);
• You have to store a copy of name and owner
• Return NULL if the function fails
*/

#include "dog.h"
#include <stdlib.h>

/**
 * print_dog - Entry point
 * Description - 'function creating a new struct new dog'
 * @name: char type
 * @age: float type
 * @owner: char type
 * Return: pointer to struct
 */

dog_t *new_dog(char *name, float age, char *owner) {
    dog_t *newD;
    int namelen = 0, ownerlen = 0, h, j;

    newD = malloc(sizeof(dog_t));

    if (newD == NULL) {
        return (NULL);
    }
    while (name[namelen]++)
        ;
    while (owner[ownerlen]++)
        ;
    (*newD).name = malloc(sizeof((*newD).name) * namelen);

    if ((*newD).name == NULL) {
        free(newD);
        return (NULL);

        for (h = 0; h < namelen; h++)
            newD->name[h] = name[h];

        newD->age = age;

        newD->owner = malloc(sizeof(newD->owner) * ownerlen);

        if (newD->owner == NULL) {
            free(newD->name);
            free(newD);
            return (NULL);
        }
        for (j = 0; j < ownerlen; j++)
            newD->owner[j] = owner[j];
    }
    return (newD);
}
