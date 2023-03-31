#include "main.h"

/**
 * int_len - compute length of integer
 * @val: integer
 * Return: integer length
 */

int int_len(int val)
{
	int len = 0;

	while (val != 0) /* obtain length of integer */
	{
		len++;
		val /= 10;
	}

	return (len);
}

/**
 * print_int - print integer
 * @args: the integer in the argument list
 * Return: number of characters printed
 */

int print_int(va_list args)
{
	int i, size = 0, start = 0, rem;
	int num = va_arg(args, int);
	int n = num;
	char buffer[1024];

	if (n < 0)
	{
		buffer[0] = '-';
		size++;
		start++;
		n *= -1;
	}

	size += int_len(n);

	for (i = 0; n > 0; i++) /* convert to string */
	{
		rem = n % 10;
		n /= 10;
		buffer[size - (i + 1)] = rem + '0';
	}
	buffer[size] = '\0';

	return (write(1, buffer, size));
}
