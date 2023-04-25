#include "main.h"

/**
 * write_number - function to handle printing of numbers
 *
 * @is_negative: variable to check negativity
 * @ind: index
 * @buffer: array to handle print
 * @flag: variable to handle active flags
 * @width: the width to handle
 * @precision: the precision specifier
 * @size: the size specifier
 *
 * Return: return the number of chars printed
*/

int write_number(int is_negative, int ind, char buffer[],
	int flag, int width, int precision, int size)
{
	int length = BUFFER_SIZE - ind - 1;
	char p = ' ', ch = 0;

	VOID(size);

	if ((flag & ZERO) && !(flag & MINUS))
		p = '0';
	if (is_negative)
		ch = '-';
	else if (flag & PLUS)
		ch = '+';
	else if (flag & SPACE)
		ch = ' ';
	return (write_num(ind, buffer, flag, width, precision,
		length, p, ch));
}
