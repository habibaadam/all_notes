#include "shell.h"
/**
  * our_getline - Entry point
  * Description - ' a function that reads input from a file stream'
  * @line_buffer: buffer that stores the input
  * @h: size of the buffer
  * @input_stream: location or where input is read from
  * Return: the number of bytes read
  */
ssize_t our_getline(char **line_buffer, size_t *h, FILE *input_stream)
{
	static char buf[SIZE_B];
	ssize_t position_b = 0, buf_size = 0;
	char **new_line_buffer;
	size_t read_c, new_s;
	char c;
	*h = SIZE_B;
	new_s = 0;
	read_c = 0;

	if (buf == NULL)
	{
		fflush(input_stream);
	}
	else
	{
		return (-1);
	}
	input_stream = 0;
	if (*line_buffer == NULL || h == 0)
	{
		*line_buffer = malloc(SIZE_B);
		if (*line_buffer == NULL)
		{
			return (-1);
		}
	}
	while (1)
	{
		if (position_b >= buf_size)
		{
			buf_size = read(STDIN_FILENO, buf, SIZE_B);
			position_b = 0;
			if (buf_size == 0)
			{
				if (read_c == 0)
				{
					return (-1);
				}
				else
				{
					break;
				}
			}
		}

	c = buf[position_b++];
	(*line_buffer)[read_c++] = c;
	if (c == '\n')
	{
		break;
	}

		c = buf[position_b++];
		(*line_buffer)[read_c++] = c;

		if (c == '\n')
			break;
	if (read_c >= *h - 1)
	{
		h += SIZE_B;
		new_s = *h + SIZE_B;
		*new_line_buffer = realloc_alt(*line_buffer, *h, new_s);
		if (*new_line_buffer == NULL)
		{
			h += SIZE_B;
			new_s = *h + SIZE_B;
			*new_line_buffer = realloc_alt(*line_buffer, *h, new_s);

			if (*new_line_buffer == NULL)
			{
				return (-1);
			}
			*line_buffer = (char *)new_line_buffer;
		}
	}
	}
	(*line_buffer)[read_c] = '\0';
	return (read_c);
}