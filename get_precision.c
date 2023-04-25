#include "main.h"

/**
 * get_precision - function to calculate the precision
 *		   for printing
 *
 * @format: the format specifier
 * @i: variable holding the list of arguments to be printed
 * @list: the list of arguments
 *
 * Return: return the precision
*/

int get_precision(const char *format, int *i, va_list list)
{
	int a = *i + 1;
	int precision = -1

	if (format[a] != '.')
		return (precision);
	precision = 0;
	for (a += 1; format[a] != '\0'; a++)
	{
		if (is_digit(format[a]))
		{
			precision *= 10;
			precision += format[a] - '0';
		}
		else if (format[a] == '*')
		{
			a++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = a - 1;
	return (precision);
}
