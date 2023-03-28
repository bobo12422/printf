#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "main.h"
<<<<<<< Updated upstream

/**
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
 * print_prcent - prints % to stdout
 * @args - @args: A va_list holding the next argument to the calling function.
 * Return: The number of characters printed
 */

int print_percent()
{
	char p = '%';
	return (write(1, &p, 1));
}

/**
* print_number - Prints an integer to stdout.
* @args: A va_list holding the next argument to the calling function.
*
* Return: The number of characters printed.
*/

int print_number(va_list args)
{
	char buffer[1024];
	int i = 0; /*J=0*/
	int n = va_arg(args, int);

	if (n < 0)
	{
		buffer[i++] = '-';
		n *= -1;
	}

	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}

	if (n == 0)
		buffer[i++] = '0';

	buffer[i] = '\0';
/*
	while (j < i / 2)
	{
		char tmp = buffer[j];

		buffer[j++] = buffer[i - j];
		buffer[i - j] = tmp;
	}
*/
	return (write(1, buffer, _strlen(buffer)));
}

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
			{'%', print_percent},
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

=======
/**
 * _printf - is a function that selects the correct function to print.
 * @format: identifier to look for.
 * Return: the length of the string.
 */
int _printf(const char * const format, ...)
{
	convert_match m[] = {
		{"%s", printf_string}, {"%c", printf_char},
		{"%%", printf_37},
		{"%i", printf_int}, {"%d", printf_dec}, {"%r", printf_srev},
		{"%R", printf_rot13}, {"%b", printf_bin}, {"%u", printf_unsigned},
		{"%o", printf_oct}, {"%x", printf_hex}, {"%X", printf_HEX},
		{"%S", printf_exclusive_string}, {"%p", printf_pointer}
	};

	va_list args;
	int i = 0, j, len = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

Here:
	while (format[i] != '\0')
	{
		j = 13;
		while (j >= 0)
		{
			if (m[j].id[0] == format[i] && m[j].id[1] == format[i + 1])
			{
				len += m[j].f(args);
				i = i + 2;
				goto Here;
			}
			j--;
		}
		_putchar(format[i]);
		len++;
		i++;
	}
	va_end(args);
	return (len);
}
>>>>>>> Stashed changes
