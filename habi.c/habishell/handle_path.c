#include "shell.h"

char *strcpy_alt(char *new, char *og);
char *handle_path(char *cmd);

/**
  * strcpy_alt - Entry point
  * Description - 'a function that copies content of one string to the other'
  * @og: original string
  * @new: destination string
  * Return: new
  */

char *strcpy_alt(char *new, char *og)
{
	int h = 0;

	while (og[h] != '\0')
	{
		new[h] = og[h];
		h++;
	}
	new[h] = '\0';

	return (new);
}

/**
*handle_path -Entry point
*Description - 'function that handles the path'
*@cmd: 'a pointer to the character inputted by the user as command'
*Return: executable command  if successfull OR
*        NULL if command is not found
*/
char *handle_path(char *cmd)
{
	/**
	  * variables for the path, its duplicate, its token,
	  * executable command's path, the length of the command
	  * and the length of each token of the command declared below
	  */
	char *path, *path_dup, *path_token, *exec_path;
	int cmd_len, tok_len;
	struct stat buffer;

	path = getenv("PATH");
	if (path)
	{
		path_dup = strdup(path);
		cmd_len = strlen_alt(cmd);
		path_token = strtok(path_dup, ":");

        if (strcmp_alt(cmd, "exit") == 0)
			{
				exit(0);
			}

		while (path_token != NULL)
		{
			tok_len = strlen_alt(path_token);
			exec_path = malloc(cmd_len + tok_len + 2);
			strcpy(exec_path, path_token);
			strcat_alt(exec_path, "/");
			strcat_alt(exec_path, cmd);

			if (stat(exec_path, &buffer)  == 0)
			{
				free(path_dup);
				return (exec_path);
			}
			else
			{
				free(exec_path);
				path_token = strtok(NULL, ":");
			}
		}
	free(path_dup);
	if (stat(cmd, &buffer) == 0)
	{
		return (cmd);
	}

	}
	return (NULL);
}
