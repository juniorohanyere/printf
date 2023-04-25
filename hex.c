#include "main.h"

/**
 * hex - function to append ascii in hexadecimal code to buffer
 *
 * @ascii_code: ASCII code
 * @buffer: array of chars
 * @i: index at which to start appending
 *
 * Return: always return 3
*/

int hex(char ascii_code, char buffer[], int i)
{
	char str[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;
	buffer[i++] = '\\';
	buffer[i++] = 'x';
	buffer[i++] = str[ascii_code / 16];
	buffer[i] = str[ascii_code % 16];
	return (3);
}
