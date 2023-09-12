#include "shell.h"

char* alternate_strtok(char* str, const char* delim)
{
   char* token;
   static char* remain = NULL; // Static variable to store the remaining part of the string

   if (str != NULL)
   {
      remain = str; // Initialize the remaining part of the string
   }

   // If no remaining string, return NULL
   if (remain == NULL || *remain == '\0')
   {
      return NULL;
   }

   // Skip leading delimiter characters
   while (*remain != '\0' && strchr(delim, *remain) != NULL)
   {
      remain++;
   }

   // If all remaining characters are delimiter characters, return NULL
   if (*remain == '0')
   {
      return NULL;
   }

   // Find the next delimiter or end of string
   token = remain;
   while (*remain != '\0' && our_strchr(delim, *remain) == NULL)
   {
      remain++;
   }

   // If a delimiter character is found, replace it with a null terminator
   if (*remain != '\0')
   {
      *remain = '\0';
      remain++;
   }

   return token;
}





/*int main(void)
{
  char str[] = "Hello World This is a test";
  const char delim[] = " \n\t\r\n\a";

  // Tokenize the string using alternate_strtok
  char* token = alternate_strtok(str, delim);

  while (token != NULL)
  {
    printf("%s\n", token);
    token = alternate_strtok(NULL, delim);
  }

  return 0;
}
*/
