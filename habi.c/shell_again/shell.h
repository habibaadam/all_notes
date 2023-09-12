#ifndef _SHELL_H
#define _SHELL_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define TOK_DEL " \n"
#define CMD_LEN 64
#define SIZE_B 1024

/* Accessing environmental variables */
extern char **environ;

/*Shell's Loop*/
void loop_ourshell();

/*Command/Input Readers */
ssize_t our_getline(char **line_buffer, size_t *buffer_size, FILE *input_stream);
char *read_command();

/*Token Handlers */
char **token_maker(char *linebuf);
char* alternate_strtok(char* str, const char* delim);
void _release(char **tokens_made);

/* Execution Handlers */
int exec_args(char **tokens_made);

/* Command Path Handler*/
char *commandExists(char *cmd);

/* Customized getenv */
char *getenv_alt(char *variable_name);

/* Memory Allocation */
void *custom_realloc(void *ptr, unsigned int old_s, size_t);

/* Built-in Command Handlers */
void blt_matcher(char **tokens_made);
void shell_exit(void);
void shell_env(void);
void set_env(const char* name, const char* value);
void unset_env(const char* name);

/**
 * 
 *
 *
 */

typedef struct Node {
    char *name;
    char *value;
    struct Node *next;
} Node;
Node *head;

int custom_setenv(const char* name, const char* value, int overwrite);
int custom_unsetenv(const char* name);
void write_environment_variables();
void free_linked_list();

/* All String Function Implementations */

size_t strlen_alt(char *s);
char *strcat_alt(char *dest, const char *src);
int strcmp_alt(char *s1, char *s2);
char *our_strchr(const char* str, int c);
char *strdup_func(const char *s);
char *strncat_alt(char *dest, char *src, int n);
size_t strspn_alt(char *s, char *accept);
int strncmp_alt(const char *s1, const char *s2, int n);
char *strcpy_alt(char *destination, char *source);
char *strncpy_alt(char *destination, char *source, int n);

/* error handlers */
void write_string(int fd, const char *str);
void print_command_info(const char *shell_name, int command_count, const char *command, const char *error_msg);
void int_to_string(int num, char *str);


#endif /* _SHELL_H */
