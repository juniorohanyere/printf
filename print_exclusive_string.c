#include "main.h"

/**
 * print_exclusive_string - function to print ascii codes
 *			    in hexa of exclusive non-printable string
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

int print_exclusive_string(va_list args, char buffer[],
	int flag, int width, int precision, int size)
{
	int i = 0, l = 0;
	char *str = va_arg(args, char *);

	VOID(flag);
	VOID(width);
	VOID(precision);
	VOID(size);

	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + l] = str[i];
		else
			l += hex(str[i], buffer, i + l);
		i++;
	}
	buffer[i + l] = '\0';
	return (write(1, buffer, i + l));
}
