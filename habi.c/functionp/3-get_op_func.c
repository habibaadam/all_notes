#include "3-calc.h"
#include <stddef.h>

/**
 * get_op_func - Entry point
 * Description 'function that selects the correct function
 * to perform the operation asked by the user'
 * @s: the operator passed as argument given by the user
 *
 * Return: a pointer to the function that corresponds to the operator given as
 * a parameter, or NULL if s does not match any of the 5 expected operators
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int h = 0;

	while (ops[h].op != NULL && *(ops[h].op) != *s)
		h++;

	return (ops[h].f);
}


