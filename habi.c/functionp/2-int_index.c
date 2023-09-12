#include "function_pointers.h"

/**
  * int_index - Entry point
  * Description - 'a function that searches for an integer'
  * @array: array of elements to be searched
  * @size: size of the array
  * @cmp: function pointer
  * Return:index of the first element for which
  * the cmp function does not return 0, or -1 if no match is found
  * or size is negative
  */

int int_index(int *array, int size, int (*cmp)(int))
{
	int h;

	if (size <= 0)
	{
		return (-1);
	}

	for (h = 0; h < size; h++)
	{
		if (cmp(array[h]) != 0)
		{
			return (h);
		}
	}
	return (-1);
}
