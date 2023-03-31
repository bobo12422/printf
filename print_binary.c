#include "main.h"

/**
 * print_binary - convert unsigned int to binary
 * @args: the unsigned int value in va_list
 * Return: number of characters
 */

int print_binary(va_list args)
{
	int i, size;
	char *b;
	int x, y, tmp;
	unsigned int num = va_arg(args, int);

	size = int_len(num);
	b = malloc(sizeof(b) * size);
	for (i = 0; num > 0; i++)
	{
		b[i] = (num % 2) + '0';
		num /= 2;
	}

	x = 0;
	y = _strlen(b) - 1;
	while (x < y)
	{
		tmp = *(b + x);
		*(b + x) = *(b + y);
		*(b + y) = tmp;
		x++, y--;
	}
	return (write(1, b, i));
}
