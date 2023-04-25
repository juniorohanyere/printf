#include "main.h"

/**
 * write_pointer - function to write a memory address
 * @buffer: Arrays of chars
 * @ind: Index at which the number starts in the buffer
 * @length: Length of number
 * @width: Wwidth specifier
 * @flag: Flags specifier
 * @p: Char representing the padding
 * @c: Char representing extra char
 * @n: Index at which padding should start
 *
 * Return: Number of written chars
*/
int write_pointer(char buffer[], int ind, int length, int width,
	int flag, char p, char c, int n)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = p;
		buffer[i] = '\0';
		if (flag & MINUS && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (c)
				buffer[--ind] = c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flag & MINUS) && p == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (c)
				buffer[--ind] = c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flag & MINUS) && p == '0')
		{
			if (c)
				buffer[--n] = c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[n], i - n) +
				write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (c)
		buffer[--ind] = c;
	return (write(1, &buffer[ind], BUFFER_SIZE - ind - 1));
}
