#include "main.h"

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
