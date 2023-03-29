#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "main.h"

/**
* _printf - Prints a formatted string to stdout.
* @format: The string to be formatted.
*
* Return: The number of characters printed.
*/

int _printf(const char *format, ...)
{
	int i = 0, j, count = 0;
	va_list args;
	fmt_t fmts[] = {{'c', print_char},
			{'s', print_string},
			{'d', print_number},
			{'i', print_number},
			{'\0', NULL}};

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			j = 0;
			while (fmts[j].type)
			{
				if (format[i + 1] == '%')
				{
					count += write(1, &format[i], 1);
					i++;
					break;
				}
				if (format[i + 1] == fmts[j].type)
				{
					count += fmts[j].func(args);
					i++;
					break;
				}
				j++;
			}
			if (!fmts[j].type)
				count += write(1, &format[i], 1);
			}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

