#include "main.h"

/**
 * write_char - function to handle the printing of a char
 * @c: the char variable
 * @buffer: the array to handle print
 * @flag: variable to handle active flags
 * @width: the width to handle
 * @precision: the precision specifier
 * @size: the size specifier
 *
 * Return: return the number of chars printed
*/

int write_char(char c, char  buffer[],
	int flag, int width, int precision, int size)
{
	int i = 0;
	char p = ' ';

	VOID(precision);
	VOID(size);

	if (flag & ZERO)
		p = '0';
	buffer[i++] = c;
	buffer[i] = '\0';
	if (width > 1)
	{
		buffer[BUFFER_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFFER_SIZE - i - 2] = p;
		if (flag & MINUS)
			return (write(1, &buffer[0], 1) +
				write(1, &buffer[BUFFER_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFFER_SIZE - i - 1], width - 1) +
				write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}
