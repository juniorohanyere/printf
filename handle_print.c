#include "main.h"

/**
 * handle_print - function to print an argument
 *		  based on its type
 *
 * @fmt: the format specifier
 * @ind: the index
 * @list: variable holding the list of parameters
 * @buffer: array to handle the print
 * @flag: variable to handle active flags
 * @width: the width to handle
 * @precision: the precision specifier
 * @size: the size specifier
 *
 * Return: return 1 0r 2
*/

int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flag, int width, int precision, int size)
{
	int i, length = 0;
	format_t formats[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percentage},
		{'i', print_integer}, {'d', print_integer},
		{'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_HEXADECIMAL},
		{'S', print_exclusive_string}, {'p', print_pointer},
		{'r', print_reverse}, {'R', print_rot13}, {'\0', NULL},
	};
	for (i = 0; formats[i].fmt != '\0'; i++)
		if (fmt[*ind] == formats[i].fmt)
			return (formats[i].func(list, buffer, flag, width, precision, size));
	if (formats[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		length += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			length += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		length += write(1, &fmt[*ind], 1);
		return (length);
	}
	return (-1);
}
