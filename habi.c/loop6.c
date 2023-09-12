#include <stdio.h>

void helloworld(char *str) {
    int h;

    for (h = 0; h < 5; h++) {
        printf("%s\n", str);
    }
}

int main(void) {
    char string[] = "Hello World";
    helloworld(string);
    return (0);
}