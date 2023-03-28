i#include "main.h"
#include <unistd.h>
#include <stdlib.h>

/**
<<<<<<< HEAD
* _strlen - Calculates the length of a string.
* @s: The string to be measured.
*
* Return: The length of the string (excluding the terminating null byte).
*/

int _strlen(char *s)
{
	int len = 0;

	while (*s++)
	len++;

	return (len);
}

/**
 * print_char - prints char
 * @args: A va_list holding the next argument to the calling function.
 * Return: The number of characters printed
 */

int print_char(va_list args)
{
	char charac = va_arg(args, int);

	return (write(1, &charac, 1));
}

/**
* print_string - Writes a string to stdout.
* @args: A va_list holding the next argument to the calling function.
* Return: The number of characters printed
*/

int print_string(va_list args)
{
	char *str = va_arg(args, char *);

	return (write(1, str, _strlen(str)));
}

/**
* _printf - Prints a formatted string to stdout.
* @format: The string to be formatted.
*
* Return: The number of characters printed.
*/

=======
 * _printf - prints a formatted string to the standard output
 * @format: format string
 *
 * Return: the number of characters printed, excluding the null byte
 */
>>>>>>> origin
int _printf(const char *format, ...)
{
	va_list args;
<<<<<<< HEAD
	fmt_t fmts[] = {{'c', print_char},
			{'s', print_string},
			{'d', print_number},
			{'i', print_number},
			{'\0', NULL}};
=======
	int printed_chars = 0;

	if (format == NULL)
		return (-1);
>>>>>>> origin

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
<<<<<<< HEAD
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
=======
				char *s = va_arg(args, char *);
				if (s == NULL)
					s = "(null)";
				printed_chars += write(1, s, _strlen(s));
>>>>>>> origin
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

