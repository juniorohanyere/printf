#include "main.h"

/**
 * is_printable - function to check if a character is printable
 * @c: char to be checked
 *
 * Return: return 0, or 1 if the char is printable
*/

int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}
