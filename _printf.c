#include "main.h"

/**
 * _printf - prints a formatted string to the standard output stream
 * @format: the format string to print
 *
 * Return: the number of characters printed (excluding the null byte used to
 *         end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, j, count = 0;
	print_t func_list[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'d', print_number},
		{'i', print_number},
		{'u', print_unsigned_number},
		{'x', print_hexadecimal_lower},
		{'X', print_hexadecimal_upper},
		{'\0', NULL}
	};

	va_start(args, format);

	if (format == NULL)
		return (-1);

	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			count++;
		}
		else
		{
			if (format[i + 1] == '\0')
				return (-1);
			for (j = 0; func_list[j].type != '\0'; j++)
			{
				if (format[i + 1] == func_list[j].type)
				{
					count += func_list[j].func(args);
					i++;
					break;
				}
			}
			if (func_list[j].type == '\0')
			{
				write(1, &format[i], 1);
				count++;
			}
		}
	}

	va_end(args);

	return (count);
}

/**
 * print_char - prints a character
 * @args: the va_list argument
 *
 * Return: the number of characters printed
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	write(1, &c, 1);

	return (1);
}

/**
 * print_string - prints a string
 * @args: the va_list argument
 *
 * Return: the number of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";

	return (write(1, str, _strlen(str)));
}

/**
 * print_percent - prints a percent character
 * @args: the va_list argument (unused)
 *
 * Return: the number of characters printed
 */
int print_percent(va_list args)
{
	(void)args;

	return (write(1, "%", 1));
}

/**
 * print_number - prints a signed integer
 * @args: the va_list argument
 *
 * Return: the number of characters printed
 */
int print_number(va_list args)
{
	char buffer[1024];
	int i = 0, j = 0, n = va_arg(args, int);

	if (n

