#include "main.h"
#include <stdio.h>

int multiply(int h, int b)
{
    int result = (h * b);
    return (result);
}

int main()
{
    int product = multiply(5, 4);
    printf("The result of 5 and 4 is %d\n", product);
    return (0);
}
