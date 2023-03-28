#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct print - struct for print functions
 * @type: the type of the argument
 * @func: the print function
 */
typedef struct print
{
	char type;
	int (*func)(va_list);
} print_t;

int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_number(va_list args);
int print_unsigned_number(va_list args);
int print_hexadecimal_lower(va_list args);
int print_hexadecimal_upper(va_list args);

#endif /* MAIN_H */

