#include "shell.h"

/**
  * search_builtins - Entry point
  * Description - 'a function that handles matching of builtin commands if in
  *                case the command is a builtin command'
  * @argv: array of arguments
  * Return: void
  */


void search_builtins(char **argv)
{
	if (strcmp_alt(argv[0], "env") == 0)
	{
		env_cmd(argv);
	}
}
