#include "shell.h"

void write_string(int fd, const char *str) {
    write(fd, str, strlen(str));
}

void print_command_info(const char *shell_name, int command_count, const char *command, const char *error_msg)
{
    char command_number[10];
    char newline = '\n';

    write_string(STDERR_FILENO, shell_name);
    write_string(STDERR_FILENO, ": ");
    int_to_string(command_count, command_number);

    write_string(STDERR_FILENO, command_number);
    write_string(STDERR_FILENO, ": ");
    write_string(STDERR_FILENO, command);
    write_string(STDERR_FILENO, ": ");
    write_string(STDERR_FILENO, error_msg);
    write(STDERR_FILENO, &newline, 1);
}


void int_to_string(int num, char *str) {
    int i = 0;
    int len = 0;
    int temp = num;

    // Calculate the number of digits in the integer
    while (temp > 0) {
        temp /= 10;
        len++;
    }

    // Convert each digit to a character and store it in the string
    for (i = len - 1; i >= 0; i--) {
        str[i] = '0' + (num % 10);
        num /= 10;
    }

    // Null-terminate the string
    str[len] = '\0';
}
