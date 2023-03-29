#include "main.h"
#include <stdio.h>
#include <stdarg.h>

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
	 * while (j < i / 2)
	 * {
	 *	char tmp = buffer[j];
	 *
	 *	buffer[j++] = buffer[i - j];
	 *	buffer[i - j] = tmp;
	 * }
	 */

	return (write(1, buffer, _strlen(buffer)));
}
