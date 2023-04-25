#include "main.h"

/**
 * get_size - function to calculate the size
 *	      to cast the argument
 *
 * @format: the format specifier
 * @i: variable holding the list of arguments
 *
 * Return: return the size
*/

int get_size(const char *format, int *i)
{
	int a = *i + 1;
	int size = 0;

	if (format[a] == 'l')
		size = LONG;
	else if (format[a] == 'h')
		size = SHORT;
	if (size == 0)
		*i = a - 1;
	else
		*i = a;
	return (size);
}
