#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * argstostr - concatenates all the arguments of a program
 * @ac: the number of arguments
 * @av: an array of strings containing the arguments
 *
 * Return: a pointer to a new string containing the concatenated arguments,
 *         or NULL if the function fails
 */

char *argstostr(int ac, char **av)
{
     char *str;
    int i, j, len, total_len = 0;

    if (ac == 0 || av == NULL)
        return (NULL);

    /* calculate the total length of the concatenated string */
    for (i = 0; i < ac; i++)
    {
        len = strlen(av[i]);
        total_len += len + 1; /* add 1 for the newline character */
    }

    /* allocate memory for the concatenated string */
    str = malloc(total_len * sizeof(char));

    if (str == NULL)
        return (NULL);

    /* concatenate the strings and add a newline character */
    for (i = 0, j = 0; i < ac; i++)
    {
        len = strlen(av[i]);
        memcpy(str + j, av[i], len);
        j += len;
        str[j++] = 'n';
    }

    /* add the terminating null byte */
    str[j] = '0';

    return (str);
}