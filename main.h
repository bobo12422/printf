#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int _putchar(char c);
int _strlen(char *s);
int print_char(va_list args);
int print_string(va_list args);
int print_int(va_list args);
int _printf(const char *format, ...);

/**
 * struct dt - struct
 * @type: format type
 * @func: function ptr
 */
typedef struct dt
{
	char type;
	int (*func)(va_list);
} fmt_t;

#endif /* MAIN_H */

