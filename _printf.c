i#include "main.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * _printf - prints a formatted string to the standard output
 * @format: format string
 *
 * Return: the number of characters printed, excluding the null byte
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				printed_chars += write(1, "%", 1);
			}
			else if (*format == 'c')
			{
				printed_chars += write(1, va_arg(args, int), 1);
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char *);
				if (s == NULL)
					s = "(null)";
				printed_chars += write(1, s, _strlen(s));
			}
			else
			{
				printed_chars += write(1, "%", 1);
				printed_chars += write(1, &(*format), 1);
			}
		}
		else
		{
			printed_chars += write(1, &(*format), 1);
		}

		format++;
	}

	va_end(args);

	return (printed_chars);
}

