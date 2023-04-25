#include "main.h"

/**
 * print_pointer - function to print a pointer type
 *
 * @args: variable holding the list of parameters
 * @buffer: array to handle the printing
 * @flag: variable to handle active flags
 * @width: the width to handle
 * @precision: the precision specification
 * @size: size specifier
 *
 * Return: return the number of characters printed
*/

int print_pointer(va_list args, char buffer[],
	int flag, int width, int precision, int size)
{
	char ch = 0, p = ' ';
	char str[] = "0123456789abcdef";
	unsigned long n;
	int i = BUFFER_SIZE - 2, length = 2, c = 1;
	void *ap = va_arg(args, void *);

	VOID(width);
	VOID(size);

	if (ap == NULL)
		return (write(1, "(nil)", 5));
	buffer[BUFFER_SIZE - 1] = '\0';
	VOID(precision);

	n = (unsigned long)ap;
	while (n > 0)
	{
		buffer[i--] = str[n % 16];
		n /= 16;
		length++;
	}
	if ((flag & ZERO) && !(flag & MINUS))
		p = '0';
	if (flag & PLUS)
		ch = '+', length++;
	else if (flag & SPACE)
		ch = ' ', length++;
	i++;
	return (write_pointer(buffer, i, length, width,
		flag, p, ch, c));
}
