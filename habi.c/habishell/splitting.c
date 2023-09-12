#include <stdio.h>
#include <stdlib.h>

#include "shell.h"


/**
* get_tokens - Entry point
* Description: tokenize user input already read'
* @buffer: pointer to user input
*
* Return: array containing individual tokens
*/


char **get_tokens(char *buffer)
{
size_t bufs = TOK_BUF;
size_t h;
char **argv = malloc(sizeof(char *) * bufs);
char **tempo;
char *buffer_dup = strdup_func(buffer);
char *token;


if (argv == NULL || buffer_dup == NULL)
{
perror(" memory alloc failed");
exit(EXIT_FAILURE);
}
token = strtok(buffer_dup, TOK_DL);
h = 0;


while (token != NULL)
{
argv[h] = strdup_func(token);
if (++h == bufs)
{
bufs += TOK_BUF;
tempo = realloc_alt(argv, sizeof(char *) * bufs, sizeof(char *) * bufs);
/* storing the content of argv temporarily by reallocating memory */

if (tempo == NULL)
{
perror("memory realloc failed");
exit(EXIT_FAILURE);
}
argv = tempo;
}
token = strtok(NULL, TOK_DL); /*storing next array tokenized*/
}
argv[h] = NULL;

free(buffer_dup);
return (argv);
}
