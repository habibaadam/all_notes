#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define CAPA 5000

/**
 * hash_function - function for hash table
 * @str: contains values maybe
 * Return - index of hash function
*/

unsigned long int hash_function(char *str){

    unsigned long h = 0;

    for (int j = 0; str[j]; j++)
        h += str[j];

        return (h % CAPA);
}

int main(void)
{
    char *str = "Hel";
    char *s = "Cau";
    unsigned long hash_value = hash_function(str);
    unsigned long hash_value_2 = hash_function(s);
    printf("Hash value: %lu\n", hash_value);
    printf("Hash value: %lu\n", hash_value_2);

    return 0;
}
