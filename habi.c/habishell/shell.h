#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define TOK_DL " \n"
#define TOK_BUF 64
#define X_OK 1 /* confirms whether a file is executable */
#define SIZE_B 1024 /* size of buffer */

/* Representing environment variables */
extern char **environ;

/* Input Readers */
char *r_input(int *char_count);
ssize_t our_getline(char **line_buffer, size_t *h, FILE *input_stream);

/* defining our_strtok*/
char *our_strtok(char *sentence, const char *seperator);

/* Splitting strings */
char **get_tokens(char *buffer);

/* Execution handlers */
void exec(char **argv);

/* Path Handlers*/
char *handle_path(char **argv);

/* Alternative String Functions */
int strlen_alt(const char *s);
char *strdup_func(const char *s);
int strcmp_alt(char *s1, char *s2);
char *strchr_alt(char *s, char c);
char *strcat_alt(char *dest, char *src);
char *strncat_alt(char *dest, char *src, int n);
int strspn_alt(char *s, char *accept);
int strncmp_alt(const char *s1, const char *s2, int n);
char *strcpy_alt(char *new, char *og);
char *strncpy_alt(char *new, char *og, int n);

/* Memory allocation handlers */
void *realloc_alt(void *ptr, unsigned int old_s, size_t new_s);

/* BuiltIn Handlers */
void search_builtins(char **argv);
void env_cmd(char **argv);
void exit_stat(char **argv);
void set_ourenv(char **argv);

/* Converters */
int atoi_alt(char *s);
int check_digit(const char *str);















#endif /* _SHELL_H_ */
