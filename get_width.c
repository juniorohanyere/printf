#include "main.h"

/**
 * get_width - function to calculate the width for printing
 *
 * @format: the format specifier
 * @i: variable holding the list of arguments
 * @list: the list of arguments
 *
 * Return: return the width
*/

int get_width(const char *format, int *i, va_list list)
{
	int a, width = 0;

	for (a = *i + 1; format[a] != '0'; a++)
	{
		if (is_digit(format[a]))
		{
			width *= 10;
			width += format[a] - '0';
		}
		else if (format[a] == '*')
		{
			a++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = a - 1;
	return (width);
}
