#include "shell.h"
#include <stdlib.h>
#include <stdio.h>


/**
 * main - Entry point
 * Description: 'main function that runs a simple UNIX command
 * -interpreter'
 * @ac: number of arguments in main function
 * @argv: array of command line arguments
 * Return: the last executed command's value
 */


int main(int ac, char **argv)
{
	(void)ac;
	(void)argv;


	while (1)
	{
		int char_count;
		int m;
		char *buffer_dup = r_input(&char_count);


		if (buffer_dup != NULL)
		{
			char **token = get_tokens(buffer_dup);

			if (token != NULL && token[0] != NULL)
			{
				search_builtins(token);

				exec(token);
			}

			free(buffer_dup);

			if (token != NULL)
			{
				for (m = 0; token[m] != NULL; m++)
				{
					free(token[m]);
				}
			}
			free(token);
		}
	}
	return (0);
}




/**
 * exec - Entry point
 * Description: 'a function that handles execution of commands after being
 * tokenized'
 * @argv: an array containing command line arguments
 * Return: void
 */


void exec_cmd(char **argv)
{
	char *cmd;
	char *actual_cmd;


	if (argv == NULL || argv[0] == NULL)
		return;


	cmd = argv[0];
	actual_cmd = handle_path(cmd);


	if (actual_cmd != NULL)
	{
		pid_t ourchild = fork();


		if (ourchild == -1)
		{
			perror("fork failed");
			exit(EXIT_FAILURE);
		}
		else if (ourchild == 0)
		{
			if (execve(actual_cmd, argv, NULL) == -1)
			{
				perror("Error:");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(NULL);
		}
	}
	else
	{
		const char *error = " :( Command can not be found: ";


		write(STDERR_FILENO, error, strlen_alt(error));
		write(STDERR_FILENO, cmd, strlen_alt(cmd));
		write(STDERR_FILENO, "\n", 2);
	}
}




