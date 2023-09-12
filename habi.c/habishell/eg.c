#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PROMPT "-_-  "
#define PROMPT_LENGTH 5
#define TOK_BUF 64
#define TOK_DL " \t\r\n\a"

void exec_cmd(char **argv);

char **get_tokens(char *buffer) {
    size_t bufs = TOK_BUF;
    size_t h = 0;
    char **argv = malloc(sizeof(char *) * bufs);
    char **tempo;
    char *buffer_dup = strdup(buffer);
    char *token;

    if (argv == NULL || buffer_dup == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    token = strtok(buffer_dup, TOK_DL);

    while (token != NULL) {
        argv[h] = strdup(token);
        if (++h == bufs) {
            bufs += TOK_BUF;
            tempo = realloc(argv, sizeof(char *) * bufs);
            if (tempo == NULL) {
                perror("Memory reallocation failed");
                exit(EXIT_FAILURE);
            }
            argv = tempo;
        }
        token = strtok(NULL, TOK_DL);
    }
    argv[h] = NULL;

    free(buffer_dup);
    return argv;
}

int main(int argc, char **argv) {
    char *buffer = NULL;
    size_t m = 0;
    ssize_t char_count;
    char **token;

    (void)argc;
    (void)argv;

    while (1) {
        write(STDOUT_FILENO, PROMPT, PROMPT_LENGTH);
        char_count = getline(&buffer, &m, stdin);

        if (char_count == -1) {
            if (buffer != NULL) {
                free(buffer);
                buffer = NULL;
            }
            write(STDOUT_FILENO, "\n", 1);
            break;  // End of file, exit the loop
        }

        if (buffer[char_count - 1] == '\n')
            buffer[char_count - 1] = '\0';

        token = get_tokens(buffer);

        if (token != NULL) {
            exec_cmd(token);
        }

        free(token);
    }

    free(buffer);
    return 0;
}

void exec_cmd(char **argv) {
    char *cmd = NULL;
    pid_t ourchild;

    if (argv != NULL) {
        cmd = argv[0];
        ourchild = fork();

        if (ourchild == -1) {
            perror("fork failed");
            exit(EXIT_FAILURE);
        } else if (ourchild == 0) {
            if (execve(cmd, argv, NULL) == -1) {
                perror("Error executing command");
                exit(EXIT_FAILURE);
            }
        } else {
            wait(NULL);
        }
    }
}
