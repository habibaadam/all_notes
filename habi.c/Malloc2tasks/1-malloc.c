/**
 * Write a function that concatenates two strings.
• Prototype: char *string_nconcat(char *s1, char *s2, unsigned int n);
• The returned pointer shall point to a newly allocated space in memory, which contains s1,
followed by the first n bytes of s2, and null terminated
• If the function fails, it should return NULL
• If n is greater or equal to the length of s2 then use the entire string s2
• if NULL is passed, treat it as an empty string
*/

#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * string_nconcat - Entry point
 * Description - ' a function that concatenates two strings with new allocated memory
 * @s1: char string type
 * @s2: char string type
 * @n : number of bytes
 * Return : pointer to allocated memory
 */

char *string_nconcat(char *s1, char *s2, unsigned int n) {
    unsigned int len1 = 0, len2 = 0, h, j;
    char *ptr;

    if (s1 == NULL) {
        s1 = "";
    }
    if (s2 == NULL) {
        s2 = "";
    }

    len1 = strlen(s1);
    len2 = strlen(s2);

    if (n >= len2) {
        n = len2;
    }

    ptr = (char *)malloc((len1 + n + 1) * sizeof(char));

    if (ptr == NULL) {
        return (NULL);
    }

    for (h = 0; h < len1; h++) {
        ptr[h] = s1[h];
    }

    for (j = 0; j < n; j++) {
        ptr[h + j] = s2[j];
    }
    ptr[h + j] = '\0';

    return (ptr);
}