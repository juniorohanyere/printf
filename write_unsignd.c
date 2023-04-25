#include "main.h"

/**
 * write_unsignd - function to writes an unsigned number
 * @is_negative: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @flag: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of written chars
*/
int write_unsignd(int is_negative, int ind, char buffer[],
	int flag, int width, int precision, int size)
{
	int length = BUFFER_SIZE - ind - 1, i = 0;
	char p = ' ';

	VOID(is_negative);
	VOID(size);

	if (precision == 0 && ind == BUFFER_SIZE - 2 && buffer[ind] == '0')
		return (0);

	if (precision > 0 && precision < length)
		p = ' ';

	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}
	if ((flag & ZERO) && !(flag & MINUS))
		p = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = p;

		buffer[i] = '\0';

		if (flag & MINUS)
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
		}
	}

	return (write(1, &buffer[ind], length));
}
