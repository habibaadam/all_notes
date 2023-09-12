#include "shell.h"

/**
 * shell_exit - handles the exit command.
 *
 * Description: 'this function is responsible
 *for exiting the shell'
 *
 * Return: void
 *
 **/

void shell_exit(void)
{
	exit(0);
}

/**
 * shell_env - handles the env command.
 *
 * Description: This function prints the envronment
 * to the standard output
 *
 * Return:void
 */
void shell_env(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		write(1, *env, strlen(*env));
		write(1, "\n", 1);
		env++;
	}
}






















/**
 * blt_matcher - a function that matches or checks for a builtin function
 * @tokens_made: pointer to user input tokenized for execution
 */
void blt_matcher(char **tokens_made)
{
    if (strcmp_alt(tokens_made[0], "exit") == 0) {
        shell_exit();
    } else if (strcmp_alt(tokens_made[0], "env") == 0) {
        shell_env();
		} else if (strcmp_alt(tokens_made[0], "setenv") == 0) {
        // Usage: setenv VARNAME VALUE
        if (tokens_made[1] != NULL && tokens_made[2] != NULL) {
            int overwrite = 1; // Set to 1 to allow overwriting of existing variable
            int result = custom_setenv(tokens_made[1], tokens_made[2], overwrite);
            if (result == -1) {
                fprintf(stderr, "Error setting environment variable: %s\n", tokens_made[1]);
            }
        } else {
            fprintf(stderr, "Usage: setenv VARNAME VALUE\n");
        }
    } else if (strcmp_alt(tokens_made[0], "unsetenv") == 0) {
        // Usage: unsetenv VARNAME
        if (tokens_made[1] != NULL) {
            int result = custom_unsetenv(tokens_made[1]);
            if (result == -1) {
                fprintf(stderr, "Error unsetting environment variable: %s\n", tokens_made[1]);
            }
        } else {
            fprintf(stderr, "Usage: unsetenv VARNAME\n");
        }
    } else {
        // Handle other commands...
        // ...
    }
}


void write_for_env(const char *str) {
    write(1, str, strlen(str));
}
