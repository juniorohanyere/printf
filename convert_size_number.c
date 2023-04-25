#include "main.h"

/**
 * convert_size_number - function to convert a number
 *			 to specified size
 *
 * @num: number to be converted
 * @size: number indicating the type to be casted
 *
 * Return: return the converted number
*/

long int convert_size_number(long int num, int size)
{
	if (size == LONG)
		return (num);
	else if (size == SHORT)
		return ((short)num);
	return ((int)num);
}
