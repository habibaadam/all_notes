#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
  * print_strings - Entry point
  * Description - 'a function that prints strings,followed by new line'
  * @separator: The string to be printed between the strings
  * @n: The number of strings passed to the function
  */

void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int h;
	char *str;

	va_list arguments;

	va_start(arguments, n);


	for (h = 0; h < n; h++)
	{
		str = va_arg(arguments, char *);

		if (str == NULL)
                {
                        printf("(nil)");
                }
                else
                {
                        printf("%s", str);
                }

		if (h != (n - 1) && separator != NULL)
		{
			printf("%s", separator);
		}
	}
	va_end(arguments);

	printf("\n");
}
