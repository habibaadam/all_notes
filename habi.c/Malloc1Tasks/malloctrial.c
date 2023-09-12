#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int *ptr;

    ptr = (int*) malloc(sizeof(int));

    if (ptr == NULL)
    {
        printf("Memory was not allocated\n");
        return (1);
    }

    *ptr = 5;

    printf("Value of %d\n", *ptr);

    free(ptr);

    return (0);

}
