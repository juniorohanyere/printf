#include "main.h"

/**
 * print_integer - function to print integer numbers
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

int print_integer(va_list args, char buffer[],
	int flag, int width, int precision, int size)
{
	int i = BUFFER_SIZE - 2;
	int n = 0;
	long int ch = va_arg(args, long int);
	unsigned long int num;

	ch = convert_size_number(ch, size);
	if (ch == 0)
		buffer[i--] = '0';
	buffer[BUFFER_SIZE - 1] = '\0';
	num = (unsigned long int)ch;
	if (ch < 0)
	{
		num = (unsigned long int)((-1) * ch);
		n = 1;
	}
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_number(n, i, buffer, flag, width, precision, size));
}
