#include "main.h"

/**
 * print_char - function to print a char
 *
 * @args: the variable holding the list of parameters
 * @buffer: array to handle the printing of the char
 * @flag: variable to calculate the active flag
 * @width: the width to handle
 * @precision: the precision to handle
 * @size: the size of the char
 *
 * Return: return the number of characters printed
*/

int print_char(va_list args, char buffer[],
	int flag, int width, int precision, int size)
{
	char str = va_arg(args, int);

	return (write_char(str, buffer, flag, width, precision, size));
}
