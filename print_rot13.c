#include "main.h"

/**
 * print_rot13 - function to print a string in ROT13
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

int print_rot13(va_list args, char buffer[],
	int flag, int width, int precision, int size)
{
	char *str, s;
	char a[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char b[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int count;
	unsigned int i, j;

	str = va_arg(args, char *);
	VOID(buffer);
	VOID(flag);
	VOID(width);
	VOID(precision);
	VOID(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; a[j]; j++)
		{
			if (a[j] == str[i])
			{
				s = b[j];
				write(1, &s, 1);
				count++;
				break;
			}
		}
		if (!a[j])
		{
			s = str[i];
			write(1, &s, 1);
			count++;
		}
	}
	return (count);
}
