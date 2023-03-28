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
* print_string - Writes a string to stdout.
* @args: A va_list holding the next argument to the calling function.
*
* Return: The number of characters printed.
*/

int print_string(va_list args)
{
char *str = va_arg(args, char *);

return (write(1, str, _strlen(str)));
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
int i = 0, j = 0, n = va_arg(args, int);

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

if (i == 0)
buffer[i++] = '0';

buffer[i] = '\0';

while (j < i / 2)
{
char tmp = buffer[j];
buffer[j++] = buffer[i - j];
buffer[i - j] = tmp;
}

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
fmt_t fmts[] = {
{'s', print_string},
{'d', print_number},
{'i', print_number},
{'\0', NULL}
};

va_start(args, format);

while (format && format[i])
{
if (format[i] == '%')
{
j = 0;
while (fmts[j].spec)
{
if (format[i + 1] == fmts[j].spec)
{
count += fmts[j].printer(args);
i++;
break;
}
j++;
}
if (!fmts[j].spec)
count += write(1, &format[i], 1);
}
else
count += write(1, &format[i], 1);
i++;
}
va_end(args);
return (count);
}

