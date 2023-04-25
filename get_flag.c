#include "main.h"

/**
 * get_flag - function to calculate active flags
 *
 * @format: the format specifier
 * @i: variable to accept parameter
 *
 * Return: return the flag
*/

int get_flag(const char *format, int *i)
{
	int a, b, flag = 0;
	const char flag_ch[] = {'-', '+', '0', '#', ' ', '\0'};
	const int flag_arr[] = {MINUS, PLUS, ZERO, HASH, SPACE, 0};

	for (a = *i + 1; format[a] != '\0'; a++)
	{
		for (b = 0; flag_ch[b] != '\0'; b++)
			if (format[a] == flag_ch[b])
			{
				flag |= flag_arr[b];
				break;
			}
		if (flag_ch[b] == 0)
			break;
	}
	*i = a - 1;
	return (flag);
}
