#include "main.h"

/**
 * print_unsigned - function to print unsigned int
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

int print_unsigned(va_list args, char buffer[],
	int flag, int width, int precision, int size)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);

	num = convert_size_unsingd(num, size);

	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFFER_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_unsingd(0, i, buffer, flag, width, precision, size));
}

