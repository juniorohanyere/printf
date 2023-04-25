#include "main.h"

/**
 * print_string - functiom to print a string
 *
 * @args: variable holding the list of parameters
 * @buffer: the array to handle the printing of the string
 * @flag: variable to handle active flags
 * @width: the width to handle
 * @precision: the precision to handle
 * @size: size of the string
 *
 * Return: return the number of characters printed
*/

int print_string(va_list args, char buffer[],
	int flag, int width, int precision, int size)
{
	int i, length = 0;
	char *str = va_arg(args, char *);

	VOID(buffer);
	VOID(flags);
	VOID(width);
	VOID(precision);
	VOID(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}
	while (str[length] != '\0')
		length++;
	if (precision >= 0 && precision < length)
		length = precision;
	if (width > length)
	{
		if (flag & MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1," ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}
	return (write(1, str, length));
}
