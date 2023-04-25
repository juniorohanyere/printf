#include "main.h"

/**
 * is_digit - function to check if a char is digit
 * @c: char to be checked
 *
 * Return: return 0, or 1 if c is a digit
*/

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
