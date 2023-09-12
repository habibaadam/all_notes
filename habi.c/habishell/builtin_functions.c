#include "shell.h"

/**
  * env_cmd - Entry point
  * Description - 'a function that prints out environment variables'
  * @argv: array of arguments
  * Return: void
  */

void env_cmd(char **argv)
{
	int h;
	char newc = '\n'; /* for newline character */
	char **store_env = environ; /* a double pointer to the environ */

(void)argv;

	if (!store_env[0]) /* if store_env is NULL, return */
	{
		return;
	}

	for (h = 0; store_env[h]; h++) /**
				   * for loop with an iterator going through
				   * all environmental variables
				   */
	{
		write(STDOUT_FILENO, store_env[h], strlen_alt(store_env[h]));
		write(STDOUT_FILENO, &newc, 1);
	}
}

/**
  * exit_stat - Entry point
  * Description - 'a function that exits the shell including the exit statuses
  *                 or arguments'
  * @argv: array of arguments
  * Return: void
  */

void exit_stat(char **argv)
{
	int stat;

	if (argv[1] != NULL && check_digit(argv[1]))
	{
		stat = atoi_alt(argv[1]);
		exit(stat);
	}
	else
	{
		exit(0);
	}
}


/**
  * set_ourenv - Entry point
  * Description - ' a function that sets an environment variable with
  *                 Command syntax: setenv VARIABLE VALUE'
  * @argv: array of command line arguments
  * Return: void
  */

void set_ourenv(char **argv)
{
	int len_name, len_val, env_c = 0, h = 0;
	char *n_var = NULL;
	char **n_env = NULL;

	if (argv[0] == NULL || argv[1] == NULL)
	{
		return;
	}
	len_name = strlen_alt(argv[0]);
	len_val = strlen_alt(argv[1]);

	n_var = malloc(len_name + len_val + 2);

	if (n_var == NULL)
	{
		return;
	}

	strcpy_alt(n_var, argv[0]);
	strcat_alt(n_var, "=");
	strcat_alt(n_var, argv[1]);

	for (h = 0; environ[h] != NULL; h++)
	{
		if (strncmp_alt(environ[h], argv[0], len_name) == 0 &&
				environ[h][len_name] == '=')
		{
			free(environ[h]);
			environ[h] = n_var;
			return;
		}
	}
/* append to environment if variable is not found */
	while (environ[env_c] != NULL)
	{
		env_c++;
	}
	n_env = malloc((env_c + 2) * sizeof(char *));

	if (n_env == NULL)
	{
		free(n_var);
		return;
	}
	for (h = 0; h < env_c; h++)
	{
		n_env[h] = environ[h];
	}
	n_env[env_c] = NULL;

	n_env[env_c + 1] = n_var;

	environ = n_env;
}
