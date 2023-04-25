#include "main.h"

/**
 * print_hex - function to print hexadecimal numbers
 *		in lower or upper case
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

int print_hex(va_list args, char buffer[],
	int flag, char f, int width, int precision, int size)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int n = num;

	VOID(width);

	num = conver_size_unsigd(num, size);
	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFFER_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}
	if (flag & HASH && n != 0)
	{
		buffer[i--] = f;
		buffer[i--] = '0';
	}
	i++;
	return (write_unsignd(0, i, buffer, flag, width, precision, size));
}
