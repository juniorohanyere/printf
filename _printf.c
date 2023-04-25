#include "main.h"

/**
 * _printf - function to print formatted characters
 *
 * @format: the format specifier for the characters
 *
 * Return: return the number of printed characters
 */

int _printf(const char *format, ...)
{
	va_list list;
	int i, p = 0, ch = 0, index = 0;
	int flag, width, precision, size;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);
	va_start(list, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[index++] = format[i];
			if (index == BUFFER_SIZE)
				print_buffer(buffer, &index);
			ch++;
		}
		else
		{
			print_buffer(buffer, &index);
			flag = get_flag(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			p = handle_print(format, &i, list, buffer, flag, width, precision, size);
			if (p == -1)
				return (-1);
			ch += printed;
		}
	}

	print_buffer(buffer, &index);

	va_end(list);

	return (ch);
}
