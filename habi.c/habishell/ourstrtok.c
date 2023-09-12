#include "shell.h"
/**
  *our_strtok - Entry point
  *Description - 'function that tokenize a string based on the seperator'
  *@sentence: the string
  *@seperator: the delimiter
  *Return: a pointer to the current token or substring.
  */
char *our_strtok(char *sentence, const char *seperator)
{
  static char *previous_token;
  char *current_token = NULL;
  int index, count, found = 0;

  if (sentence != NULL)
  {
  previous_token = sentence;
  }
  if (previous_token == NULL)
  {
    return (NULL);
  }
  index = 0;
  while (previous_token[index] != '\0')
  {
    count = 0;
    while (seperator[count] != '\0')
    {
      if (previous_token[index] == seperator[count])
      {
        previous_token[index] = '\0';
        current_token = previous_token;
        previous_token = &previous_token[index + 1];
        found = 1; /* seperator found*/
        break;
      }
      count++;
    }
    if (found)
    {
      break;
    }
    index++;
  }
  if (!found)
  {
    current_token = previous_token;
    previous_token = NULL;
  }
  return (current_token);
}