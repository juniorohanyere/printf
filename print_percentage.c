#include "main.h"

/**
 * print_percentage - function to print percentage
 *
 * @args: variable holding the list of parameters
 * @buffer: array to handle the printing of the percentage
 * @flag: variable to handle active flags
 * @width: the width to handle
 * @precision: the precision specification
 * @size: the size specifier
 *
 * Return: return the number of characters printed
*/

int print_percentage(va_list args, char buffer[],
	int flag, int width, int precision, int size)
{
	VOID(args);
	VOID(buffer);
	VOID(flag);
	VOID(width);
	VOID(precision);
	VOID(size);
	return (write(1, "%%", 1));
}
