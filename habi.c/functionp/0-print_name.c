#include "function_pointers.h"
#include <stdio.h>

/**
  * print_name - Entry point
  * Description - 'function that prints a name'
  * @name: pointer storing char
  * @f: function pointer
  * Return: void
  */

void print_name(char *name, void (*f)(char *))
{
	if (name == NULL)
	{
		return;
	}

	f(name);
}

