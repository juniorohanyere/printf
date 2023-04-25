#include "main.h"

/**
 * print_binary - function to print binary numbers
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

int print_binary(va_list args, char buffer[],
	int flag, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	VOID(buffer);
	VOID(flag);
	VOID(width);
	VOID(precision);
	VOID(size);

	n = va_arg(args, unsigned int);
	m = 2147483648;	/* 2 raised to the power of 31 */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0; sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char str = '0' + a[i];

			write(1, &str, 1);
			count++;
		}
	}
	return (count);
}
