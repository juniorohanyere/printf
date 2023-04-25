#include "main.h"

/**
 * print_ - function to print string in reverse
 *
 * @args: variable holding the list of parameters
 * @buffer: array to handle the printing
 * @flag: variable to handle active flags
 * @width: the width to handle
 * @precision: the precision specification
 * @size: size specifier
 *
 * Return: return the number of characters printed
*/

int print_reverse(va_list args, char buffer[],
	int flag, int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	VOID(buffer);
	VOID(flag);
	VOID(width);
	VOID(size);

	str = va_arg(args, char *);
	if (str == NULL)
	{
		VOID(precision);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;
	for (i = i - 1; i >= 0; i--)
	{
		char s = str[i];

		write(1, &s, 1);
		count++;
	}
	return (count);
}
