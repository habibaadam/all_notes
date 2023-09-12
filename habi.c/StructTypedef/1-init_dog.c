/**
* Write a function that initialize a variable of type struct dog
• Prototype: void init_dog(struct dog *d, char *name, float age, char
* owner);
*
*/

#include "dog.h"
#include <stdlib.h>

/**
 * init_dog - Entry point
 * Description - 'function that initializes a variable for struct
 * @d : pointer acessing struct dog
 * @name: char type
 * @age: float type
 * @owner: char type
 * Return: void
 */

void init_dog(struct dog *d, char *name, float age, char *owner) {
    if (d != NULL) {
        d->name = name;
        d->age = age;
        d->owner = owner;
    }
}
