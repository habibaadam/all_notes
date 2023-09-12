#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * r_input - Entry point
 * Description: 'function reading user input and exiting with EOF condition'
 * @char_count: Return value of the getline function, storing user input
 *
 * Return: user input
 */


char* r_input(int* char_count)
{/**
  * this function handles reading user input, the getline
  * function and exiting the shell with EOF condition
  */

	/* char *usr_prompt = "$ "; */
    char *buffer = NULL;
    size_t buffer_size = 0;
	
	*char_count = getline(&buffer, &buffer_size, stdin);

    return buffer;
}

