#include "main.h"

/**
 * print_HEXADECIMAL - function to print hexadecimal numbers
 *		       in upper case
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

int print_HEXADECIMAL(va_list args, char buffer[],
	int flag, int width, int precision, int size)
{
	return (print_hex(args, "0123456789ABCDEF", buffer,
		flag, 'X', width, precision, size));
}
