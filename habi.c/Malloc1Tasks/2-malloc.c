/* Write a function that concatenates two strings.
* • Prototype: char *str_concat(char *s1, char *s2);
* • The returned pointer should point to a newly allocated space in memory which contains 
* the contents of s1, followed by the contents of s2, and null terminated
* • if NULL is passed, treat it as an empty string
* • The function should return NULL on failure
*/


#include "main.h"
#include <string.h>
#include <stdlib.h>

/**
 * str_concat - Entry point
 * Description - 'a function concantenating two strings, using malloc'
 * @s1: char string type
 * @s2: char string type
 * Return: pointer to newly allocated space
*/

char *str_concat(char *s1, char *s2)
{
    int len1 = 0; /*storing length of string 1*/
    int len2 = 0; /*storing length of string2*/
    int h; /*iterator for for loops*/

    /*IF null is passed, treat it as an empty string*/

    if (s1 == NULL)
    {
        s1 = "";
    }
    if (s2 == NULL)
    {
        s2 = "";
    }

    for (h = 0; s1[len1] != '\0'; h++) 
    {
        len1++;
    }

    for (h = 0; s2[len2] != '\0'; h++)
    {
        len2++;
    }

    char *addlens = malloc((len1 + len2 + 1)* sizeof(char)); /*allocating new memory to store concantenated string*/

    if (addlens == NULL)
    {
        return (NULL);
    }

    for (h = 0; h < len1; h++)
	{
		addlens[h] =  s1[h];
	}
    
    int j;

    for (j = 0; j < len2; j++)
	{
		addlens[h + j] = s2[j];
	}

	return (addlens);
}
