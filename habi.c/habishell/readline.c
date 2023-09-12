#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


/**
 * our_getline - Entry point
 * Description - 'a function that reads user input from a stream'
 * @linebuffer: pointer to the buffer containing bytes read
 * @m: size of the buffer
 * @stream: location to read input from
 * Return: input read
 */

ssize_t readline(char** lineptr, size_t* n, FILE* stream) {
    if (*lineptr == NULL) {
        *n = 1; // Set initial buffer size to 1
        *lineptr = (char*)malloc(*n * sizeof(char));
        if (*lineptr == NULL) {
            perror("Memory allocation error");
            return -1;
        }
    }

    size_t position = 0;
    ssize_t bytesRead;
    char c;

    while ((bytesRead = read(fileno(stream), &c, sizeof(char))) > 0) {
        if (c == '\n') {
            break;
        }

        if (position >= *n - 1) {
            *n *= 2; // Double the buffer size
            char* temp = (char*)malloc(*n * sizeof(char));
            if (temp == NULL) {
                perror("Memory allocation error");
                return -1;
            }
            strncpy(temp, *lineptr, position);
            free(*lineptr);
            *lineptr = temp;
        }

        (*lineptr)[position] = c;
        position++;
    }

    if (bytesRead == 0 && position == 0) {
        return -1;
    }

    (*lineptr)[position] = '\0'; // Null-terminate the string
    return position;
}


int main(int ac, char **argv)
{
    size_t m = 0;
    char *linebuffer = NULL;
    ssize_t get_result;

    (void)ac;
    (void)argv;

    while (1)
    {
        char our_prompt[] = ":) ";

        if (isatty(STDIN_FILENO))
        {
            write(STDOUT_FILENO, our_prompt, sizeof(our_prompt) - 1);
            fflush(stdout);
        }

        while ((get_result = our_getline(&linebuffer, &m, stdin)) != -1)
        {
            if (linebuffer[get_result - 1] == 'n')
                linebuffer[get_result - 1] = '0';

            if (isatty(STDIN_FILENO))
            {
                write(STDOUT_FILENO, our_prompt, sizeof(our_prompt) - 1);
                fflush(stdout);
            }
        }

        printf("EOF detected. Shell exiting... n");
        free(linebuffer);
        return (0);
    }
