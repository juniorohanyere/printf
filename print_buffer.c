#include "main.h"

/**
 * print_buffer - function to print the contents
 *		  of the buffer if it exits
 * @buffer: array of characters
 * index: the index at which to print the next character
 *
 * Return: return nothing
*/

void print_buffer(char buffer[], int *index)
{
	if (*index > 0)
		write(1, &buffer[0], *index);
	*index = 0;
}
