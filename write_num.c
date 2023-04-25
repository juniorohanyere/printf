#include "main.h"

/**
 * write_num - function to write a number using a bufffer
 * @ind: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @flag: variable to handle active flags
 * @width: width
 * @prec: Precision specifier
 * @length: Number length
 * @p: Pading char
 * @c: Extra char
 *
 * Return: Number of printed chars
 */
int write_num(int ind, char buffer[], int flag, int width,
	int prec, int length, char p, char c)
{
	int i, n = 1;

	if (prec == 0 && ind == BUFFER_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFFER_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = p = ' ';
	if (prec > 0 && prec < length)
		p = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (c != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = p;
		buffer[i] = '\0';
		if (flag & MINUS && p == ' ')
		{
			if (c)
				buffer[--ind] = c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flag & MINUS) && p == ' ')
		{
			if (c)
				buffer[--ind] = c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flag & MINUS) && p == '0')
		{
			if (c)
				buffer[--n] = c;
			return (write(1, &buffer[n], i - n) +
				write(1, &buffer[ind], length - (1 - n)));
		}
	}
	if (c)
		buffer[--ind] = c;
	return (write(1, &buffer[ind], length));
}
