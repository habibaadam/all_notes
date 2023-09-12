#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_numbers - Entry point
 * Description -'a function that prints numbers, followed by a new line'
 * @separator: The string to be printed between numbers.
 * @n: number of integers passed to the function
 * @...: A variable number of numbers to be printed
 *
 * Return: void
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int h;

	va_list arguments;

	va_start(arguments, n);

	for (h = 0; h < n; h++)
	{
		printf("%d", va_arg(arguments, int));

/* if separator is not null and h is not the last argument, print seperator*/

	if (h != (n - 1) && separator != NULL)
		printf("%s", separator);
	}

	va_end(arguments);

	printf("\n"); /*Print a new line at the end of your function */
}
