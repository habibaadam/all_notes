#include "shell.h"
/**
 * exec_args - Uses execve and fork to create processes to execute commands
 * @tokens_made: double pointer to commands/tokens
 * Return: 0 if sucessful or bring out an error message for failure
 */
int exec_args(char **tokens_made)
{
	int condition, cmd_count = 1; 
	const char *errcmd, *shell_name, *errmsg;
	char *cmd; 
	pid_t ourchild;

	if (tokens_made[0] == NULL)
	{
		return (1);
	}
	else
	{

		blt_matcher(tokens_made); /* handle built_ins if presented */

		ourchild = fork();
		if (ourchild == -1)
		{perror("child process failed to be created");
			return (1);
		}
		if (!ourchild)
		{
			cmd = commandExists(tokens_made[0]);
			shell_name = "./hsh", cmd_count = 1, errmsg = "not found";
			errcmd = tokens_made[0];
			if (cmd == NULL)
			{
				print_command_info(shell_name, cmd_count, errcmd, errmsg);
				cmd_count++;
				return (0);
			}
			if (execve(cmd, tokens_made, environ) == -1)
			{perror(cmd);
				free(cmd);
				return (0);
			} 
		}
		else
		{
			wait(&condition);
			
		}
	}
	return (-1);
}
