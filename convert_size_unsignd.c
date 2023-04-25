#include "main.h"

/**
 * convert_size_unsignd - function to convert an unsigned
 *			  to a specified size
 *
 * @num: the unsigned variable to be converted
 * @size: number indicating the size of the number to be converted
 *
 * Return: return the converted value of num
*/

long int convert_size_unsignd(unsigned long int num, int size)
{
	if (size == LONG)
		return (num);
	else if (size == SHORT)
		return ((unsigned short)num);
	return ((unsigned int)num);
}
