#include "shell.h"

/**
  * realloc_alt - Entry point
  * Description: 'a function that rellocate a block of memory using malloc
  *                'and free'
  * @ptr: pointer to new memory block
  * @new_s: new size
  * @old_s: old size
  * Return: pointer to new memory block when sucessful
  */

void *realloc_alt(void *ptr, size_t new_s)
{
	char *relo, *dup;
	unsigned int m;
	unsigned int old_s;

	if (ptr != NULL)
		dup = ptr;
	else
	{ return (malloc(new_s)); }
	if (new_s == old_s)
		return (ptr);
	if (new_s == 0 && ptr != NULL)
	{ free(ptr);
		return (0); }
	relo = malloc(new_s);
	if (relo == NULL)
		return (NULL);
	for (m = 0; m < old_s && m < new_s; m++)
	{
		*(relo + m) = dup[m];
	}
	free(ptr);
return (relo);
}

int atoi_alt(char *s)
{
	int res_value = 0;
	int sn = 1;
	int h = 0;

	while (s[h] == ' ' || s[h] == '\t' || s[h] == '\n')
	{
		h++;
	}

	if (s[h] == '+' || s[h] == '-')
	{
		sn = (s[h++] == '-') ? -1 : 1;
	}

	while (s[h] >= '0' && s[h] <= '9')
	{
		res_value = res_value * 10 + (s[h] - '0');
		h++;
	}

return (res_value * sn);
}

/**
 * check_digit - Entry point
 * Description - 'checks if a digit is a digit that ranges from 0 to 255'
 * @str: contains digit to be checked
 * Return: 1 if digit is in range and 0 if it is not
 */

int check_digit(const char *str)
{
	int digit = 0;

	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
		{
			return (0);
		}

		digit = digit * 10 + (*str - '0');

		if (digit > 255)
		{
			return (0);
		}
		str++;
	}

	return (1);
}

/**
  * strncpy_alt - Entry point
  * Description - 'a function that copies a string with a maximum number of
  *                bytes'
  * @new: destination char string type
  * @og: source string type
  * @n: maximum number of bytes to be copied
  * Return: pointer to new
  */

char *strncpy_alt(char *new, char *og, int n)
{
	int m;

	for (m = 0; m < n && og[m] != '\0'; m++)
	{
		new[m] = og[m];
	}
	for (; m < n; m++)
	{
		new[m] = '\0';
	}
	return (new);
}